#include <string>
#include <utility>

#include "print_vector.hpp"

#include <gtest/gtest.h>

#include "solution.hpp"

typedef std::vector<int> vi;
typedef std::vector<long long> vl;

class KThPalindromeTest :public ::testing::TestWithParam<std::tuple<vi, int, vl>> {
protected:
    Solution solution;
};

TEST_P(KThPalindromeTest, CheckSolution) {
    vi input = std::get<0>(GetParam());
    int k = std::get<1>(GetParam());
    vl expected = std::get<2>(GetParam());

    vl actual = solution.kthPalindrome(input, k);

    ASSERT_EQ(expected.size(), actual.size())
      << "Expected " << expected << std::endl
      <<"Got " << actual;
    for (size_t i = 0; i < actual.size(); ++i) {
      ASSERT_EQ(expected[i], actual[i])
        << "Difference at position " << i << ", for query " << input[i] << std::endl
        << "Expected " << expected << std::endl << "Got " << actual;
    }
}

INSTANTIATE_TEST_SUITE_P(
  KThPalindromeTests,
  KThPalindromeTest,
        ::testing::Values(
          std::make_tuple<vi, int, vl>({ 1,2,3,4,5,90 }, 3, { 101,111,121,131,141,999 }),
          std::make_tuple<vi, int, vl>({ 2,4,6 }, 4, { 1111,1331,1551 }),
          std::make_tuple<vi, int, vl>({ 2,201429812,8,520498110,492711727,339882032,462074369,9,7,6 }, 1, { 2,-1,8,-1,-1,-1,-1,9,7,6 }),
          std::make_tuple<vi, int, vl>(
            { 875,90,209,416,62,647,398,909,669,186,492,748,662,80,414,550,866,358,744,478,19,637,501,129,635,358,867,723,874,454,882,406,360,516,632,883,771,21,358,147,109,472,447,493903904,808,94,645,707,98043237,573,508,142,142,855,498,56,993,355,572,788,977,646,279,821,530,726,631,61,362,136,814,357,105,829909848,645,855,862,635,451,888,609788691,961592349,386,884,536,334,585,71,612 },
            15, 
            { 100008747800001,100000898000001,100002080200001,100004151400001,100000616000001,100006464600001,100003979300001,100009080900001,100006686600001,100001858100001,100004919400001,100007474700001,100006616600001,100000797000001,100004131400001,100005494500001,100008656800001,100003575300001,100007434700001,100004777400001,100000181000001,100006363600001,100005000500001,100001282100001,100006343600001,100003575300001,100008666800001,100007222700001,100008737800001,100004535400001,100008818800001,100004050400001,100003595300001,100005151500001,100006313600001,100008828800001,100007707700001,100000202000001,100003575300001,100001464100001,100001080100001,100004717400001,100004464400001,-1,100008070800001,100000939000001,100006444600001,100007060700001,-1,100005727500001,100005070500001,100001414100001,100001414100001,100008545800001,100004979400001,100000555000001,100009929900001,100003545300001,100005717500001,100007878700001,100009767900001,100006454600001,100002787200001,100008202800001,100005292500001,100007252700001,100006303600001,100000606000001,100003616300001,100001353100001,100008131800001,100003565300001,100001040100001,-1,100006444600001,100008545800001,100008616800001,100006343600001,100004505400001,100008878800001,-1,-1,100003858300001,100008838800001,100005353500001,100003333300001,100005848500001,100000707000001,100006111600001 })
  )
);

class ReversedPalindromeTest :public ::testing::TestWithParam<std::tuple<int, int, int, int>> {
protected:
  Solution solution;
};

TEST_P(ReversedPalindromeTest, CheckSolution) {
  int input = std::get<0>(GetParam());
  int mid = std::get<1>(GetParam());
  int k = std::get<2>(GetParam());
  int expected = std::get<3>(GetParam());

  auto actual = solution.getNumber(input, mid, k);

  ASSERT_EQ(expected, actual);
}

INSTANTIATE_TEST_SUITE_P(
  ReversedPalindromeTests,
  ReversedPalindromeTest,
  ::testing::Values(
    std::make_tuple<int, int, int, int>(2, 1, 1, 212),
    std::make_tuple<int, int, int, int>(21, 3, 2, 21312),
    std::make_tuple<int, int, int, int>(21, -1, 2, 2112)
  )
);

TEST(KThNumberTest, Check1) {
  Solution s;
  ASSERT_EQ(-1, s.getNth(98043237, true, 15));
}