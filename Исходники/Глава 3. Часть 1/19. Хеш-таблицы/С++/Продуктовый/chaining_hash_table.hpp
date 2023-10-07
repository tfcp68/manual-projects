#include <functional>  // для std::hash
#include <list>        // корзина
#include <vector>      // массив корзин

template <
    typename ReferenceType,
    typename TableIterator,
    typename BucketIterator>
class ChainingHashTableIterator {
public:
    typedef std::remove_reference_t<ReferenceType> value_type;
    typedef ReferenceType reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef std::forward_iterator_tag iterator_category;

private:
    typedef TableIterator table_iterator;
    typedef typename table_iterator::value_type bucket;
    typedef typename bucket::iterator bucket_iterator;

public:
    // конструкторы, деструктор и операторы присваивания
    ChainingHashTableIterator(
        table_iterator table_it,
        table_iterator table_end,
        bucket_iterator bucket_it) : _table_it(table_it),
                                     _table_end(table_end),
                                     _bucket_it(bucket_it) {
        // необходимо проитерироваться от
        // начального итератора _table_it до первого
        // встретившегся элемента
        if (_table_it != _table_end and _bucket_it == _table_it->end())
            ++(*this);
    }

    ChainingHashTableIterator(const ChainingHashTableIterator& other) = default;

    ChainingHashTableIterator(ChainingHashTableIterator&& other) = default;

    ~ChainingHashTableIterator() = default;

    ChainingHashTableIterator& operator=(const ChainingHashTableIterator& other) = default;

    ChainingHashTableIterator& operator=(ChainingHashTableIterator&& other) = default;

    // операции доступа к элементу
    reference operator*() const {
        return *_bucket_it;
    }

    pointer operator->() const {
        return &(*_bucket_it);
    }

    // операции инкремента
    ChainingHashTableIterator& operator++() {
        // алгоритм перехода:
        // следуем вперёд по корзине
        // если корзина пройдена, то нужно перейти к следующей
        // не пустой корзине
        ++_bucket_it;
        if (_bucket_it == _table_it->end()) {
            ++_table_it;
            while (_table_it != _table_end and _table_it->empty())
                ++_table_it;
            if (_table_it != _table_end)
                _bucket_it = _table_it->begin();
        }
        return *this;
    }

    ChainingHashTableIterator operator++(int) {
        ChainingHashTableIterator tmp(*this);
        ++(*this);
        return tmp;
    }

    // операторы сравнения
    bool operator==(const ChainingHashTableIterator& other) const {
        return this->_is_end() and other._is_end() or _table_it == other._table_it and _bucket_it == other._bucket_it;
    }

    bool operator==(ChainingHashTableIterator&& other) const {
        return this->operator==(other);
    }

    bool operator!=(const ChainingHashTableIterator& other) const {
        return !(*this == other);
    }

    bool operator!=(ChainingHashTableIterator&& other) const {
        return this->operator!=(other);
    }

private:
    bool _is_end() const {
        return _table_it == _table_end;
    }

private:
    // текущий итератор по массиву корзин и конец массива корзин
    table_iterator _table_it, _table_end;
    // итератор по корзине
    bucket_iterator _bucket_it;
};

// аргументы шаблона:
// хранимый тип данных
// оператор сравнения элементов
// хэш функция для элементов
template <
    typename ValueType,
    typename EqOperator = std::equal_to<ValueType>,
    typename Hash = std::hash<ValueType>>
class ChainingHashTable {
public:
    typedef ValueType value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef std::ptrdiff_t difference_type;
    typedef Hash hash_type;
    typedef EqOperator equal_type;
    typedef std::size_t size_type;

private:
    typedef std::list<value_type> bucket;
    typedef std::vector<bucket> table;

public:
    typedef ChainingHashTableIterator<reference,
                                      typename table::iterator, typename bucket::iterator>
        iterator;
    typedef ChainingHashTableIterator<const_reference,
                                      typename table::const_iterator, typename bucket::iterator>
        const_iterator;

public:
    // конструкторы, деструктор, операторы присваивания

    // default_capacity - начальный размер массива корзин
    // hash, eq - функции хэширования и сравнения элементов
    // max_load_factor - коэффициент загрузки таблицы, при достижении которого необходимо расширять массив корзин
    // rehash_multiplier - коэффициент расширения массива корзин
    ChainingHashTable(
        size_type default_capacity = 10,
        const hash_type& hash = hash_type(),
        const equal_type& eq = equal_type(),
        double max_load_factor = 0.7,
        double rehash_multiplier = 2.0) : _size(0),
                                          _table(default_capacity),
                                          _hash(hash),
                                          _eq(eq),
                                          _max_load_factor(max_load_factor),
                                          _rehash_multiplier(rehash_multiplier) {}

    ChainingHashTable(const ChainingHashTable& other) = default;

    ChainingHashTable(ChainingHashTable&& other) = default;

    ~ChainingHashTable() = default;

    ChainingHashTable& operator=(const ChainingHashTable& other) = default;

    ChainingHashTable& operator=(ChainingHashTable&& other) = default;

    // геттеры
    size_type size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    double load_factor() const {
        return static_cast<double>(_size) / _table.size();
    }

    // основные операции

    // операция вставки
    void insert(const value_type& value) {
        if (load_factor() > _max_load_factor)
            _rehash();
        size_type index = _hash(value) % _table.size();
        bucket& b = _table[index];
        for (auto it = b.begin(); it != b.end(); ++it)
            if (_eq(*it, value)) {
                *it = value;
                return;
            }
        b.push_back(value);
        ++_size;
    }

    void insert(value_type&& value) {
        if (load_factor() > _max_load_factor)
            _rehash();
        size_type index = _hash(value) % _table.size();
        bucket& b = _table[index];
        for (auto it = b.begin(); it != b.end(); ++it)
            if (_eq(*it, value)) {
                *it = value;
                return;
            }
        b.push_back(std::move(value));
        ++_size;
    }

    // операция удаления элемента
    // если элемент был удалён, то вернётся true, иначе false
    bool erase(const value_type& value) {
        size_type index = _hash(value) % _table.size();
        bucket& b = _table[index];
        for (auto it = b.begin(); it != b.end(); ++it)
            if (_eq(*it, value)) {
                b.erase(it);
                --_size;
                return true;
            }
        return false;
    }

    bool erase(value_type&& value) {
        return this->erase(value);
    }

    // операция проверки на содержание элемента value
    bool contains(const value_type& value) const {
        size_type index = _hash(value) % _table.size();
        const bucket& b = _table[index];
        for (auto it = b.begin(); it != b.end(); ++it)
            if (_eq(*it, value))
                return true;
        return false;
    }

    bool contains(value_type&& value) const {
        return this->contains(value);
    }

    void clear() {
        for (auto& b : _table)
            b.clear();
        _size = 0;
    }

    // операция получения итератора на элемент value
    // если такой элемент не содержится, вернётся end()
    iterator find(const value_type& value) {
        size_type index = _hash(value) % _table.size();
        bucket& b = _table[index];
        for (auto it = b.begin(); it != b.end(); ++it)
            if (_eq(*it, value))
                return iterator(_table.begin() + index, _table.end(), it);
        return this->end();
    }

    iterator find(value_type&& value) {
        return this->find(value);
    }

    const_iterator find(const value_type& value) const {
        size_type index = _hash(value) % _table.size();
        const bucket& b = _table[index];
        for (auto it = b.begin(); it != b.end(); ++it)
            if (_eq(*it, value))
                return const_iterator(_table.begin() + index, _table.end(), it);
        return this->cend();
    }

    const_iterator find(value_type&& value) const {
        return this->find(value);
    }

    // операции итераторов
    iterator begin() {
        auto table_begin = this->_table.begin();
        return {table_begin, this->_table.end(), table_begin->begin()};
    }

    iterator end() {
        auto table_end = this->_table.end();
        return {table_end, table_end, table_end->begin()};
    }

    const_iterator cbegin() const {
        auto table_begin = this->_table.begin();
        return {table_begin, this->_table.end(), table_begin->begin()};
    }

    const_iterator cend() const {
        auto table_end = this->_table.end();
        return {table_end, table_end, table_end->begin()};
    }

private:
    // расширение массива корзин
    void _rehash() {
        size_type new_size = _table.size() * _rehash_multiplier;
        this->_table.resize(new_size);
    }

private:
    size_type _size;
    table _table;
    hash_type _hash;
    equal_type _eq;
    double _max_load_factor;
    double _rehash_multiplier;
};
