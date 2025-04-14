#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct extended_gcd_result {
    T gcd;
    T coeff_a, coeff_b;
};

template <typename T>
extended_gcd_result<T> extended_gcd(T a, T b) {
    T x = a, y = b;
    T ax = 1, ay = 0;
    T bx = 0, by = 1;
    while (x) {
        T k = y / x;
        y %= x;
        ay -= k * ax;
        by -= k * bx;
        std::swap(x, y);
        std::swap(ax, ay);
        std::swap(bx, by);
    }
    return {y, ay, by};
}

template <typename T>
T mod_inv(T a, T m) {
    a %= m;
    a = a < 0 ? a + m : a;

    T x = a, y = m;
    T vx = 1, vy = 0;
    while (x) {
        T k = y / x;
        y %= x;
        vy -= k * vx;
        std::swap(x, y);
        std::swap(vx, vy);
    }
    return vy < 0 ? m + vy : vy;
}

template <int MOD_>
struct mnum {
    static constexpr int MOD = MOD_;

private:
    int v;

public:
    mnum() : v(0) {}

    mnum(int64_t v_) : v(int(v_ % MOD)) {
        if (v < 0)
        {
            v += MOD;
        }
    }

    explicit operator int() const {
        return v;
    }

    friend std::ostream &operator<<(std::ostream &out, const mnum &n) {
        return out << int(n);
    }

    friend std::istream &operator>>(std::istream &in, mnum &n) {
        int64_t v_;
        in >> v_;
        n = mnum(v_);
        return in;
    }

    friend bool operator==(const mnum &a, const mnum &b) {
        return a.v == b.v;
    }

    friend bool operator!=(const mnum &a, const mnum &b) {
        return a.v != b.v;
    }

    mnum inv() const {
        mnum res;
        res.v = mod_inv(v, MOD);
        return res;
    }

    friend mnum inv(const mnum &m) {
        return m.inv();
    }

    mnum neg() const {
        mnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }

    friend mnum neg(const mnum &m) {
        return m.neg();
    }

    mnum operator-() const {
        return neg();
    }

    mnum operator+() const {
        return mnum(*this);
    }

    mnum &operator++() {
        v++;
        if (v == MOD)
            v = 0;
        return *this;
    }

    mnum &operator--() {
        if (v == 0)
            v = MOD;
        v--;
        return *this;
    }

    mnum &operator+=(const mnum &o) {
        v -= MOD - o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }

    mnum &operator-=(const mnum &o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }

    mnum &operator*=(const mnum &o) {
        v = int(int64_t(v) * int64_t(o.v) % MOD);
        return *this;
    }

    mnum &operator/=(const mnum &o) {
        return *this *= o.inv();
    }

    friend mnum operator++(mnum &a, int) {
        mnum r = a;
        ++a;
        return r;
    }

    friend mnum operator--(mnum &a, int) {
        mnum r = a;
        --a;
        return r;
    }

    friend mnum operator+(const mnum &a, const mnum &b) { return mnum(a) += b; }
    friend mnum operator-(const mnum &a, const mnum &b) { return mnum(a) -= b; }
    friend mnum operator*(const mnum &a, const mnum &b) { return mnum(a) *= b; }
    friend mnum operator/(const mnum &a, const mnum &b) { return mnum(a) /= b; }
};

template <typename T>
T pow(T a, long long b)
{
    T r = 1;
    while (b) {
        if (b & 1) {
            r *= a;
        }
        b >>= 1;
        a *= a;
    }
    return r;
}

using num = mnum<998244353>;