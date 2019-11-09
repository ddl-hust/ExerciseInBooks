/**
 *
 *  @ brief 用模板重写P465 内存管理类
 *  基本就是将 string用类型T替换
 * @ elements :内存分配首元素
 * @ first_free : 指向最后一个实际元素后一个地址
 * @ cap: 指向分配的内存末尾后一个位置
 *
 */
#include <memory>
template <typename T>
class vec
{
public:
    vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    vec(const vec &);
    vec &operator=(const vec &);
    ~vec();

    //一些基本操作
    void push_back(const T &);
    size_t size(){return first_free - elements;}; //vec 元素个数
    size_t capacity(){return cap - elements;};    //vec 内存分配大小

    T *begin() { return elements; }
    T *end() { return first_free; }
    //emplace_back()
    template<typename ... Args>
    void emplace_back(Args&&...);

private:
    T *elements;
    T *first_free;
    T *cap;
    std::allocator<T> alloc;

    //utility
    void reallocate(); //获取更多内存，并move已有元素到新内存空间
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void free();
    void wy_alloc_n_move(std::size_t n);
    std::pair<T *, T *> alloc_n_copy(T *b, T *e); //在新的内存空间拷贝，返回<begin,end>
};

template <typename  T>
void vec<T>::reallocate()
{
    auto newcap=size()?2*size():1;
    auto newdata = alloc.allocate(newcap);
    auto dest=newdata; //新内存首地址
    auto elem=elements;
    for (size_t i = 0; i !=size(); ++i) {
            alloc.construct(dest++,std::move(*elem++)); //使用T 移动构造函数
    }
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcap;
}

template<typename T>
template<typename Args ...>
void vec<T>::emplace_back(Args&&... res)
{
    cnk_n_alloc();
    alloc.construct(first_free++,std::forward<Args>(res)...);
}