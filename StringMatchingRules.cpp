size_t HammingDistance(const string x, const string y, const size_t length){
    size_t result{0};
    for(size_t i = 1; i <= length; ++i){
        result += (x[i-1] ^ y[i-1]);//conferir lógica
    }
    return result;
} //funcionando para strings digitadas não pelo usuário

