class Solution {
public:
    double util(double x, int n) {
        if (n == 0)
            return 1;
        double ans;
        if (n % 2 == 0) {
            double temp = util(x, n / 2);
            ans = temp * temp;
        } else {
            double temp = util(x, n / 2);
            ans = x * temp * temp;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        long long tempN = n;
        if (n < 0)
            tempN *= -1;
        double ans = util(x, tempN);
        return n > 0 ? ans : (1.0 / ans);
    }
};