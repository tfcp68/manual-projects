#ifndef OPEN_ADDRESSING_HASH_TABLE_HPP
#define OPEN_ADDRESSING_HASH_TABLE_HPP

#include <functional>  // для std::hash
#include <vector>      // для массива корзин

template <typename IndexType>
struct Probing {
    typedef IndexType index_type;

    virtual ~Probing() = default;

    virtual index_type operator()(index_type start,
                                  index_type iteration) const = 0;
};

template <
    typename IndexType = std::size_t,
    typename AddFunction = std::plus<IndexType>,
    typename MultiplyFunction = std::multiplies<IndexType>>
struct LinearProbing : Probing<IndexType> {
    using index_type = typename Probing<IndexType>::index_type;
    typedef AddFunction add_type;
    typedef MultiplyFunction multiply_type;

    LinearProbing(
        index_type step = 1,
        add_type add_func = add_type(),
        multiply_type multiply_func = multiply_type()) : step(step), add_func(add_func), multiply_func(multiply_func) {}

    index_type operator()(index_type start,
                          index_type iteration) const override {
        return add_func(start, multiply_func(step,
                                             iteration));
    }

private:
    index_type step;
    add_type add_func;
    multiply_type multiply_func;
};

template <
    typename IndexType = std::size_t,
    typename AddFunction = std::plus<IndexType>,
    typename MultiplyFunction = std::multiplies<IndexType>>
struct QuadraticProbing : Probing<IndexType> {
    using index_type = typename Probing<IndexType>::index_type;
    typedef AddFunction add_type;
    typedef MultiplyFunction multiply_type;

    QuadraticProbing(
        index_type step = 1,
        add_type add_func = add_type(),
        multiply_type multiply_func = multiply_type()) : step(step), add_func(add_func), multiply_func(multiply_func) {}

    index_type operator()(index_type start,
                          index_type iteration) const override {
        auto value = multiply_func(step, iteration);
        return add_func(start, multiply_func(value, value));
    }

private:
    index_type step;
    add_type add_func;
    multiply_type multiply_func;
};

template <typename ValueType>
struct OpenAddressingHashTableBucket {
    enum OpenAddressingHashTableBucketState {
        EMPTY,
        DELETED,
        OCCUPIED,
    };

    typedef ValueType value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef OpenAddressingHashTableBucketState state_type;

    // конструкторы, деструктор и операторы присваивания
    OpenAddressingHashTableBucket() : _ptr(nullptr), _state(state_type::EMPTY) {}

    OpenAddressingHashTableBucket(const value_type& value) : _ptr(new value_type(value)), _state(state_type::OCCUPIED) {}

    OpenAddressingHashTableBucket(value_type&& value) : _ptr(new value_type(std::move(value))), _state(state_type::OCCUPIED) {}

    OpenAddressingHashTableBucket(const OpenAddressingHashTableBucket& other) : _ptr(new value_type(*other._ptr)), _state(other._state) {}

    OpenAddressingHashTableBucket(OpenAddressingHashTableBucket&& other) : _ptr(other._ptr), _state(other._state) {
        other._ptr = nullptr;
    }

    ~OpenAddressingHashTableBucket() {
        delete _ptr;
    }

    OpenAddressingHashTableBucket& operator=(const OpenAddressingHashTableBucket& other) {
        if (this != &other) {
            delete _ptr;
            _ptr = new value_type(*other._ptr);
            _state = other._state;
        }
        return *this;
    }

    OpenAddressingHashTableBucket& operator=(OpenAddressingHashTableBucket&& other) {
        if (this != &other) {
            delete _ptr;
            _ptr = other._ptr;
            other._ptr = nullptr;
            _state = other._state;
        }
        return *this;
    }

    // геттеры и сеттеры
    state_type state() const {
        return this->_state;
    }

    reference operator*() {
        return *_ptr;
    }

    const_reference operator*() const {
        return *_ptr;
    }

    void set_value(const value_type& value) {
        if (_ptr == nullptr)
            _ptr = new value_type(value);
        else
            *_ptr = value;
        _state = state_type::OCCUPIED;
    }

    void set_value(value_type&& value) {
        if (_ptr == nullptr)
            _ptr = new value_type(std::move(value));
        else
            *_ptr = std::move(value);
        _state = state_type::OCCUPIED;
    }

    // удалить значение в корзине
    void erase() {
        delete _ptr;
        _ptr = nullptr;
        _state = state_type::DELETED;
    }

    // функции проверки состояния корзины
    operator bool() const {
        return _state == state_type::OCCUPIED;
    }

    bool can_set() const {
        return _state == state_type::EMPTY or _state == state_type::DELETED;
    }

private:
    pointer _ptr;
    state_type _state;
};

// аргументы шаблона:
// ReferenceType - тип ссылки на объект (обычная или const)
// TableIterator - тип итератора по массиву корзин
template <
    typename ReferenceType,
    typename TableIterator>
class OpenAddressingHashTableIterator {
public:
    typedef std::remove_reference_t<ReferenceType> value_type;
    typedef ReferenceType reference;
    typedef value_type* pointer;
    typedef std::ptrdiff_t difference_type;
    typedef std::forward_iterator_tag iterator_category;

private:
    typedef TableIterator table_iterator;
    typedef typename table_iterator::value_type bucket;

public:
    // конструкторы, деструктор и операторы присваивания
    OpenAddressingHashTableIterator(table_iterator it, table_iterator end) : _it(it), _end(end) {
        // необходимо дошагать до первой встретившейся
        // корзины, хранящей значение
        while (_it != _end and not *_it)
            ++_it;
    }

    OpenAddressingHashTableIterator(const OpenAddressingHashTableIterator& other) = default;

    OpenAddressingHashTableIterator(OpenAddressingHashTableIterator&& other) = default;

    ~OpenAddressingHashTableIterator() = default;

    OpenAddressingHashTableIterator& operator=(const OpenAddressingHashTableIterator& other) = default;

    OpenAddressingHashTableIterator& operator=(OpenAddressingHashTableIterator&& other) = default;

    // операции доступа к элементу
    reference operator*() {
        return **_it;
    }

    pointer operator->() {
        return &**_it;
    }

    // операции инкремента
    OpenAddressingHashTableIterator& operator++() {
        ++_it;
        while (_it != _end and not *_it)
            ++_it;
        return *this;
    }

    OpenAddressingHashTableIterator operator++(int) {
        auto tmp = *this;
        ++*this;
        return tmp;
    }

    // операции сравнения
    bool operator==(const OpenAddressingHashTableIterator& other) const {
        return _it == other._it;
    }

    bool operator==(OpenAddressingHashTableIterator&& other) const {
        return _it == other._it;
    }

    bool operator!=(const OpenAddressingHashTableIterator& other) const {
        return !(*this == other);
    }

    bool operator!=(const OpenAddressingHashTableIterator&& other) const {
        return !(*this == other);
    }

private:
    table_iterator _it, _end;
};

// аргументы шаблона:
// аналогичны реализации на цепочках
// Probing - функция генерации индексов
// последовательности открытой адресации
template <
    typename ValueType,
    typename EqOperator = std::equal_to<ValueType>,
    typename Probing = QuadraticProbing<std::size_t>,
    typename Hash = std::hash<ValueType>>
class OpenAddressingHashTable {
public:
    typedef ValueType value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef std::ptrdiff_t difference_type;
    typedef Hash hash_type;
    typedef Probing probing_type;
    typedef EqOperator equal_type;
    typedef std::size_t size_type;

private:
    typedef OpenAddressingHashTableBucket<value_type> bucket;
    typedef std::vector<bucket> table;

public:
    typedef OpenAddressingHashTableIterator<reference, typename table::iterator> iterator;
    typedef OpenAddressingHashTableIterator<const_reference, typename table::const_iterator> const_iterator;

public:
    // конструкторы, деструктор и операторы присваивания
    // аргументы аналогичны реализации на цепочках
    // probing - функция генерации последовательности
    // открытой адресации
    OpenAddressingHashTable(
        size_type default_capacity = 10,
        const hash_type& hash = hash_type(),
        const probing_type& probing = probing_type(),
        const equal_type& eq = equal_type(),
        double max_load_factor = 0.7,
        double rehash_multiplier = 2.0) : _size(0), _table(default_capacity), _hash(hash), _probing(probing), _eq(eq), _max_load_factor(max_load_factor), _rehash_multiplier(rehash_multiplier) {}

    OpenAddressingHashTable(const OpenAddressingHashTable& other) = default;

    OpenAddressingHashTable(OpenAddressingHashTable&& other) = default;

    ~OpenAddressingHashTable() = default;

    OpenAddressingHashTable& operator=(const OpenAddressingHashTable& other) = default;

    OpenAddressingHashTable& operator=(OpenAddressingHashTable&& other) = default;

    // геттеры
    size_type size() const {
        return this->_size;
    }

    bool empty() const {
        return this->_size == 0;
    }

    double load_factor() const {
        return static_cast<double>(this->_size) / this->_table.size();
    }

    // основные функции
    // операция вставки
    void insert(const value_type& value) {
        // элемент может уже храниться в структуре
        // поэтому сначала нужно попытаться найти уже существующий элемент
        auto iter = this->find(value);
        if (iter != this->end()) {
            *iter = value;
            return;
        }
        // если структура загружена
        // или не найден индекс для вставки
        // нужно расширить массив корзин
        if (this->load_factor() > this->_max_load_factor)
            this->_rehash();
        auto index = this->_find_index(value, true);
        if (index >= this->_table.size()) {
            this->_rehash();
            this->insert(value);
            return;
        }
        auto& bucket = this->_table[index];
        bucket.set_value(value);
        ++this->_size;
    }

    void insert(value_type&& value) {
        auto iter = this->find(value);
        if (iter != this->end()) {
            *iter = std::move(value);
            return;
        }
        if (this->load_factor() > this->_max_load_factor)
            this->_rehash();
        auto index = this->_find_index(value, true);
        if (index >= this->_table.size()) {
            this->_rehash();
            this->insert(value);
            return;
        }
        auto& bucket = this->_table[index];
        bucket.set_value(std::move(value));
        ++this->_size;
    }

    // операция удаления
    // возвращает true, если элемент был удалён
    // false, если элемент не был найден
    bool erase(const value_type& value) {
        auto index = this->_find_index(value);
        if (index >= this->_table.size())
            return false;
        auto& bucket = this->_table[index];
        if (not bucket)
            return false;
        bucket.erase();
        --this->_size;
        return true;
    }

    bool erase(value_type&& value) {
        return this->erase(value);
    }

    // операция проверки на содержание элемента
    // возвращает true, если value хранится в структуре
    // данных, иначе false
    bool contains(const value_type& value) const {
        auto index = this->_find_index(value);
        if (index >= this->_table.size())
            return false;
        auto& bucket = this->_table[index];
        return bool(bucket);
    }

    bool contains(value_type&& value) const {
        return this->contains(value);
    }

    // операция очистки таблицы
    void clear() {
        for (auto& bucket : this->_table)
            bucket.erase();
        this->_size = 0;
    }

    // операции получения итератора на value
    // если value не найден, то вернётся end()
    iterator find(const value_type& value) {
        auto index = this->_find_index(value);
        if (index >= this->_table.size() or not this->_table[index])
            return this->end();
        return {this->_table.begin() + index, this->_table.end()};
    }

    iterator find(value_type&& value) {
        return this->find(value);
    }

    const_iterator find(const value_type& value) const {
        auto index = this->_find_index(value);
        if (index >= this->_table.size() or not this->_table[index])
            return this->cend();
        return {this->_table.cbegin() + index,
                this->_table.cend()};
    }

    const_iterator find(value_type&& value) const {
        return this->find(value);
    }

    // операции итераторов
    iterator begin() {
        return {this->_table.begin(), this->_table.end()};
    }

    iterator end() {
        return {this->_table.end(), this->_table.end()};
    }

    const_iterator cbegin() const {
        return {this->_table.begin(), this->_table.end()};
    }

    const_iterator cend() const {
        return {this->_table.end(), this->_table.end()};
    }

private:
    // операция расширения таблицы
    void _rehash() {
        size_type new_size = _table.size() * _rehash_multiplier;
        table new_table(new_size);
        // перенос всех непустых элементов
        // в новый массив корзин
        for (auto& bucket : _table) {
            if (bucket) {
                auto index = _hash(*bucket) % new_size;
                size_type iteration = 0;
                while (new_table[index]) {
                    index = _probing(index, iteration);
                    ++iteration;
                }
                new_table[index] = std::move(bucket);
            }
        }
        _table = std::move(new_table);
    }

    // операция поиска подходящей позиции для элемента
    // возвращает индекс подходящей корзины для value
    // виды возвращаемых индексов:
    // 1. индекс, выходящий за пределы массива корзин
    // 2. корзина по индексу пуста
    // 3. в корзине по индексу находится value
    size_type _find_index(const value_type& value, bool for_add = false) const {
        size_type index = _hash(value) % _table.size();
        size_type iteration = 1;
        while (index < this->_table.size()) {
            auto& bucket = _table[index];
            if (for_add and bucket.can_set())
                return index;
            else if (bucket.state() == bucket::state_type::EMPTY or
                     bucket.state() == bucket::state_type::OCCUPIED and
                         _eq(*bucket, value))
                return index;
            index = _probing(index, iteration);
            ++iteration;
        }
        return index;
    }

private:
    size_type _size;
    table _table;
    hash_type _hash;
    probing_type _probing;
    equal_type _eq;
    double _max_load_factor;
    double _rehash_multiplier;
};

#endif  // OPEN_ADDRESSING_HASH_TABLE_HPP
