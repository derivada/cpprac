#include <bits/stdc++.h>
using namespace std;

// Es bueno desactivarlas para debuggear
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

// Tipos
#define ll long long   // 64 bits INT
#define ld long double // 80 bits FP

// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 1e9 + 7;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;        // Infinito
const ld EPS = 1e-9;       // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

// Estructuras de datos
#define ar array
typedef vector<int> vi;
typedef pair<int, int> pi;
#define umap unordered_map
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end() // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for (int i = a; i <= b; i++)

string inverso(int divisor, int n) // 1 / a
{
    // 1 / a con n digitos
    string result = "0.";
    int resto = 10 % divisor, dec = 0;
    result += '0' + (10 / divisor);
    dec++;
    while (resto != 0 && dec < n)
    {
        resto *= 10;
        result += '0' + (resto / divisor);
        resto %= divisor;
        dec++;
    }
    while (dec < n)
    {
        result += '0';
        dec++;
    }

    return result;
}

string sumar(string a, string b, int n) // a + b
{
    string result;
    result += '0';
    result += '.';
    int carry = 0;
    stack<int> digits;

    for (int i = n + 1; i > 1; i--)
    {
        int sum = a[i] + b[i] + carry - '0' - '0';
        carry = sum / 10;
        digits.push(sum % 10 + '0');
    }
    while (!digits.empty())
    {
        result += digits.top();
        digits.pop();
    }
    return result;
}

string restar(string a, string b, int n) // a - b
{
    string result;
    result += '0';
    result += '.';
    int carry = 0;
    stack<int> digits;
    for (int i = n + 1; i > 1; i--)
    {
        int sum = a[i] - b[i] - carry;
        if (sum < 0)
        {
            sum += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        digits.push(sum % 10 + '0');
    }
    while (!digits.empty())
    {
        result += digits.top();
        digits.pop();
    }
    return result;
}

bool solve()
{
    int N = 0, M = 0;
    cin >> N;
    if (!N)
        return false;
    cin >> M;
    if(M == 0){
        cout << "1." <<"\n";
        return true;
    }
    int a = 3;
    int signo = -1;
    string result = "1.";
    for (int i = 0; i < M; i++)
    {
        result += '0';
    }

    for (int i = 1; i < N; i++)
    {
        string siguiente = inverso(a, M);
        if (signo == 1)
            result = sumar(result, siguiente, M);
        else
            result = restar(result, siguiente, M);
        a += 2;
        signo = -signo;
        //cout << "DEBUG (PARCIAL): " << result << "\n";
    }
    cout << result << "\n";
    return true;
}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Archivos I/O, BORRAR AL SUBIR
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve())
        ;
}