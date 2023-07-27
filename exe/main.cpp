#include <Windows.h>
#include <cstdio>
#include <vector>
#include <ranges>
#include <format>

template<typename E, size_t N>
auto len(const E (&)[N]) -> size_t {
    return N;
}


int main() {
    using std::printf;
    namespace views = std::views;
    int arr[] = {1, 2, 3, 4, 5};
    auto ret = arr
               | views::filter([](int i) { return (i%2) != 0; })
               | views::transform([](int i) { return std::to_string(i); });
    for (auto val: ret) {
        printf("str: %s\n", val.c_str());
    }

    printf("%s\n", std::format("{} {}", "string",len(arr)).c_str());
    return 0;
}