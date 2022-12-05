#include <iostream>
#include <vector>

class CombinationSet
{
private:
    int n;
    int *element;
    int r;

public:
    CombinationSet()
    {
        std::cout << "Generated Combination Set Object." << std::endl;
        std::cout << "Nを入力してください: ";
        std::cin >> n;
        std::cout << "rを入力してください: ";
        std::cin >> r;
        element = new int[n];

        for (int i = 0; i < n; i++)
        {
            std::cout << "要素を入力してください[" << i + 1 << "/" << n << "] ";
            std::cin >> element[i];
        }
    }

    void PrintElementCombination();
    void PatternIndex(std::vector<std::vector<int>>& result);
};

void CombinationSet::PrintElementCombination()
{
    std::cout << "組み合わせ（重複なし）" << std::endl;
    std::cout << "[";

    int *pattern = new int[r];

    for (int i = 0; i < r; i++)
    {
        pattern[i] = i;
        std::cout << element[pattern[i]];
        if (i != r - 1)
            std::cout << ",";
        else
            std::cout << "]" << std::endl;
    }

    while (pattern[0] < n - r)
    {
        for (int i = r - 1; i >= 0; i--)
        {
            if (pattern[i] < n - r + i)
            {
                pattern[i]++;
                for (int j = i; j < r - 1; j++)
                {
                    pattern[j+1] = pattern[j] + 1;
                }
                break;
            }
        }

        std::cout << "[";
        for (int i = 0; i < r; i++)
        {
            std::cout << element[pattern[i]];
            if (i != r - 1)
                std::cout << ",";
            else
                std::cout << "]" << std::endl;
        }
    }

    delete(pattern);
}

void CombinationSet::PatternIndex(std::vector<std::vector<int>>& result)
{
    std::cout << "組み合わせ（重複なし）出力中..." << std::endl;
    int *pattern = new int[r];

    for (int i = 0; i < r; i++)
    {
        pattern[i] = i;
    }

    std::vector<int> p(pattern, pattern + r);
    result.push_back(p);

    while (pattern[0] < n - r)
    {
        for (int i = r - 1; i >= 0; i--)
        {
            if (pattern[i] < n - r + i)
            {
                pattern[i]++;
                for (int j = i; j < r - 1; j++)
                {
                    pattern[j+1] = pattern[j] + 1;
                }
                break;
            }
        }
        std::vector<int> p(pattern, pattern + r);
        result.push_back(p);
    }

    delete(pattern);
    std::cout << "完了" << std::endl;
}

int main()
{
    CombinationSet cs;
    std::vector<std::vector<int>> pa;
    cs.PatternIndex(pa);

    for (int i = 0; i < pa.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << pa[i][j] << ",";
        }

        std::cout << std::endl;
    }

    return 0;
}