template <typename T> // 泛型，让它可以存储任何类型（int, string等）
class DynamicArray {
private:
    T* data;         // ① 原始指针：存储数据的底层数组
    int currentSize; // ② 记录当前数组中元素的数量
    int capacity;    // ③ 记录底层数组当前能容纳的最大元素数量

public:
    // 构造函数
    DynamicArray();
    // 析构函数：释放内存！
    ~DynamicArray(); 

    // 核心方法声明
    void push_back(const T& element);
    int size() const { return currentSize; } // 获取元素数量
private:
    // 关键的内存扩容函数（内部使用）
    void resizeAndCopy(); 
};
