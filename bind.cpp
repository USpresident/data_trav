#include <functional>
#include <vector>
#include <iostream>

using namespace std;

struct Data {
    int x;
    int y;
};

// 数据集
vector<Data> g_value {{1, 2}, {4, 9}, {8, 17}};

// 类用于遍历某个数据集，并在对目标项调用外部处理函数处理
class TravData {
public:
    TravData(function<void(Data)> func, int x) : m_func(func), m_x(x) {}

    ~TravData() {}

    void traverse() {
        for (auto value : g_value) {
            if (m_x == value.x) {
                m_func(value);
            }
        }
    }

private:
    function<void(Data)> m_func; // 不能是引用
    int m_x;
};

// 外表需要遍历每隔元素，对元素处理
void print(Data val)
{
    cout << "(" << val.x << ", " << val.y << "), ";
}

// 使用
int main()
{
    // std::bind(print, std::placeholders::_1) 的类型是 std::function<void(Data)>
    TravData t1(bind(print, placeholders::_1), 1);
    g_value.push_back({1, 6});
    t1.traverse();

    return 0;
}
