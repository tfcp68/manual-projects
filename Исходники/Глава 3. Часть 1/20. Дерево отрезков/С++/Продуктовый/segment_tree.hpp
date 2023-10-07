#include <cmath>   // для вычисления ближайшей степени 2 к числу
#include <vector>  // динамический массив для хранения структуры

// аргументы шаблона:
// N - количество элементов для хранения
// ValueType - хранимый тип данных
// FunctionType - тип функции для вычисления её на отрезке
template <
    std::size_t N,
    typename ValueType,
    typename FunctionType>
class SegmentTree {
public:
    typedef ValueType value_type;
    typedef FunctionType function_type;
    typedef std::size_t size_type;

private:
    typedef std::vector<value_type> container_type;

public:
    // конструкторы, деструктор и операторы присваивания
    SegmentTree(
        const value_type &neutral_value = value_type(),
        const function_type &function = function_type()) : _tree(2 * size(), neutral_value),
                                                           _neutral(neutral_value),
                                                           _func(function) {}

    // конструктор из последовательности
    template <typename InputIterator>
    SegmentTree(
        InputIterator first,
        InputIterator last,
        const value_type &neutral_value = value_type(),
        const function_type &function = function_type()) : SegmentTree(neutral_value, function) {
        build(first, last);
    }

    SegmentTree(const SegmentTree &other) = default;

    SegmentTree(SegmentTree &&other) = default;

    ~SegmentTree() = default;

    SegmentTree &operator=(const SegmentTree &other) = default;

    SegmentTree &operator=(SegmentTree &&other) = default;

    // допустимое количество хранимых элементов
    // ближайшая степень 2, которая не меньше N
    static constexpr size_type size() {
        return std::pow(2, std::ceil(std::log2(N)));
    }

    // основные функции
    // очистка дерева = заполнение его нейтральными элементами
    void clear() {
        std::fill(_tree.begin(), _tree.end(), _neutral);
    }

    // построить дерево заново из заданной последовательности
    // если длина последовательности превосходит size(),
    // то в дерево будет добавлено ровно size() элементов из
    // последовательности
    template <typename InputIterator>
    void build(InputIterator first, InputIterator last) {
        clear();
        if (std::distance(first, last) > size())
            for (int i = 0; i < size(); ++i)
                _tree[i + size()] = *first++;
        else
            std::copy(first, last, _tree.begin() + size());
        _rebuild_tree(size(), 2 * size());
    }

    // назначение value по индексу index
    // должно выполняться: 0 <= index < size()
    void update(size_type index, const value_type &value) {
        if (index >= size())
            throw std::out_of_range("index out of range");
        index += size();
        _tree[index] = value;
        _rebuild_tree(index, index + 1);
    }

    // запросить значение функции на полуинтервале [l; r)
    // должно выполняться: 0 <= l < r <= size()
    value_type query(size_type l, size_type r) const {
        if (l >= r)
            throw std::invalid_argument("l >= r");
        if (l >= size() || r > size())
            throw std::out_of_range("index out of range");
        l += size();
        r += size() - 1;
        value_type result = _neutral;
        while (l < r) {
            if (_is_right_child(l)) {
                result = _func(result, _get_node_value(l));
                ++l;
            }
            if (_is_left_child(r)) {
                result = _func(result, _get_node_value(r));
                --r;
            }
            l = _parent(l);
            r = _parent(r);
        }
        if (l == r)
            result = _func(result, _get_node_value(l));
        return result;
    }

private:
    // утилитарные методы

    // обновление дерева на отрезке
    // l, r - индексы в массиве, представляющем дерево
    // должно выполняться: 0 <= l < r <= 2 * size()
    void _rebuild_tree(size_type l, size_type r) {
        while (l > 0) {
            if (_is_right_child(l)) {
                _tree[_parent(l)] = _func(_get_node_value(l - 1), _get_node_value(l));
                ++l;
            }
            if (_is_left_child(r - 1)) {
                _tree[_parent(r)] = _func(_get_node_value(r - 1), _get_node_value(r));
                --r;
            }
            for (size_type i = l; i < r; i += 2)
                _tree[_parent(i)] = _func(_get_node_value(i), _get_node_value(i + 1));
            l = _parent(l);
            r = _parent(r);
        }
    }

    // методы с узлами
    // переход к левому потомку
    static size_type _left_child(size_type node) {
        return 2 * node;
    }

    // переход к правому потомку
    static size_type _right_child(size_type node) {
        return 2 * node + 1;
    }

    // переход к родителю
    static size_type _parent(size_type node) {
        return node / 2;
    }

    // проверка, что node является левым сыном
    static bool _is_left_child(size_type node) {
        return !_is_root(node) && node % 2 == 0;
    }

    // проверка, что node является правым сыном
    static bool _is_right_child(size_type node) {
        return !_is_root(node) && node % 2 == 1;
    }

    // проверка, что node является корнем дерева
    static bool _is_root(size_type node) {
        return node < 2;
    }

    // получить значение в node
    // если node выходит на пределы дерева,
    // будет возвращён нейтральный элемент
    value_type _get_node_value(size_type node) const {
        if (node >= 2 * size())
            return _neutral;
        return _tree[node];
    }

    // аналогично _get_node_value
    value_type operator[](size_type pos) const {
        return _get_node_values(pos);
    }

    // операции итерации
    auto begin() const {
        return _tree.begin() + size();
    }

    auto end() const {
        return _tree.end();
    }

    auto cbegin() const {
        return _tree.cbegin() + size();
    }

    auto cend() const {
        return _tree.cend();
    }

private:
    container_type _tree;
    function_type _func;
    value_type _neutral;
};
