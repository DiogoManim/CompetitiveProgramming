void solve(){

}

int main(){
    solve();

    return 0;
}


// Diogo Manim - COMPUTER SCIENCE @FCUP - COMPETITIVE PROGRAMMING 2024

// SPOJ UPDATE IT

// Um array com n elementos (inicialmente todos 0)
// Fazer um número de operações de update sobre o array
// Cada operação de update tem um l, r e val que correspondem ao index inicial, index final e valor a ser adicionado
// Após u updates, há q queries, cada uma com um index para o qual é suposto imprimir o elemento desse index

// INPUT:
// Primeira linha: t
// Cada caso de teste: n u
// Seguem-se u linhas, no formato: l r val
// Próxima linha: q
// Seguem-se q linhas, no formato: i

// OUTPUT:
// Para cada query q, imprimir o elemento nessa posição, um por linha

// HINTS: BITree with range update + single query

// LINK: spoj.com/problems/UPDATEIT/