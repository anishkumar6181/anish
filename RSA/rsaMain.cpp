// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

ll key1, key2;
ll n;


// ll *generatePrimes()
// {
//     ll x[5];
//     x[0] = 1;
//     return x;
// }


ll binpow(ll a, ll b, ll mod)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

ll gcd(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1;
    ll res = gcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return res;
}

void setKeys()
{
    ll prime1 = 13;
    ll prime2 = 17;

    ll x, y;

    n = prime1 * prime2;
    ll phi = (prime1 - 1) * (prime2 - 1);
    ll e = 2;

    while (true)
    {
        if (gcd(e, phi, &x, &y) == 1)
            break;
        e++;
    }

    key1 = e;
    ll d;
    d = 2;

    while (true)
    {
        if ((d * e) % phi == 1)
            break;
        d++;
    }

    // ll k = 2;
    // d = (1 + (k * phi)) / e;

    key2 = d;
}

ll encrypt(ll message)
{
    ll e = key1;
    ll encrpyted_text = binpow(message, e, n);
    return encrpyted_text;
}

ll decrypt(ll encrpyted_text)
{
    ll d = key2;
    ll decrypted = binpow(encrpyted_text, d, n);
    return decrypted;
}

vector<ll> encoder(string message)
{
    vector<ll> msg;
    for (auto &letter : message)
        msg.push_back(encrypt((ll)letter));
    return msg;
}

string decoder(vector<ll> encoded)
{
    string s;
    for (auto &num : encoded)
        s += decrypt(num);
    return s;
}


int main()
{
    setKeys();
    string s = "Hi There o man how are you??";
    cout<<"Original  Message : "<<s <<endl;

    vector<ll> v = encoder(s);
    cout << "Encrypted Message : ";

    for_each(v.begin(), v.end(), [](const auto &elem)
             { cout << elem; });

    cout << "\nDecrypted Message : ";
    string sh = decoder(v);
    cout << sh << endl;

    return 0;
}