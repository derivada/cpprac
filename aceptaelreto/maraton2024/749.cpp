using namespace std;
#include <bits/stdc++.h>

// Palabras clave de C++
#define se  if
#define senao  else
#define mentres  while
#define para  for
#define facer  do
#define interrompe  break
#define continuar  continue
#define retorno  return
#define principal  main
#define incluir  include
#define espazo_de_nomes  namespace
#define voido  void
#define enteiro  int
#define longo  long
#define charactere  char
#define cadea  string
#define verdadeiro  true
#define falso  false
#define alineado inline
#define booleano bool

// Estruturas de datos STL
#define conxunto  set
#define mapa  map
#define vector  vector
#define fio  string
#define pila  stack
#define cola  queue
#define cola_de_prioridade  priority_queue
#define lista  list
#define par  pair

// Funcións comúns
#define tamano  size
#define engadir  insert
#define atopar  find
#define borrar  erase
#define baleiro  empty
#define empuxar  push
#define empuxar_tras  push_back
#define empuxar_frente  push_front
#define pop_tras  pop_back
#define pop_frente  pop_front
#define superior  top
#define fronte  front
#define atras  back
#define entrada_de_c cin  
#define saida_de_c cout  
#define fin_da_linha endl  
#define principio start
#define final end

// Outros
#define enteiro_longo long long    // 64 bits
#define dobre_longo long double    // 80 bits
#define PI 3.1415926535897932384626433832795l
typedef vector<enteiro> vector_de_enteiros;
typedef par<enteiro, enteiro> par_de_enteiros;
typedef vector<vector<enteiro>> grafico;
typedef vector<vector<par_de_enteiros>> grafico_pesado;
#define mapa_desordenado unordered_map
#define conxunto_desordenado unordered_set
#define Primeiro first
#define Segundo second
#define empuxar_tras push_back
#define facer_par make_pair
#define depurar(x) cout << #x << " é " << x << endl
#define tamano_de(x) ((enteiro)x.size())
#define todo(a) (a).begin(), (a).end()  // toda a estrutura
#define F0R(i, n) for (enteiro i = 0; i < n; i++)
#define R0F(i, n) for (enteiro i = n - 1; i >= 0; i--)
#define PARA(i, a, b) for (enteiro i = a; i < b; i++)
#define RPARA(i, a, b) for (enteiro i = b - 1; i >= a; i--)
#define entrada_rapida cin.sync_with_stdio(0);cin.tie(0);
const enteiro_longo MOD = 1e9 + 7; // cambiar o valor de MOD

alineado booleano resolver() {
    enteiro_longo n, m, h;
    entrada_de_c >> n >> m >> h;
    se (!n && !m && !h) retorno falso;
    enteiro_longo resposta = n*(m-1) + m*(n-1);
    conxunto<par_de_enteiros> rem;
    enteiro dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    F0R(i, h) {
        enteiro x, y;
        entrada_de_c >> x >> y;
        enteiro adxunto = 0;
        se (rem.atopar(facer_par(x, y)) != rem.final())
            continuar;
        F0R(j, 4) {
            enteiro nx = dx[j] + x, ny = dy[j] + y;
            se (nx >= 1 && nx <= n && ny >= 1 && ny <= m && 
                rem.atopar(facer_par(nx, ny)) == rem.final()) {
                adxunto++;
            }
        }
        resposta -= adxunto;
        rem.engadir(facer_par(x, y));
    }
    saida_de_c << resposta << fin_da_linha;
    retorno verdadeiro;
}

enteiro principal() {
    entrada_rapida;
    mentres (resolver());
}