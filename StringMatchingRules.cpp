size_t HammingDistance(const string x, const string y, const size_t length){
    size_t result{0};
    for(size_t i = 1; i <= length; ++i){
        result += (x[i-1] ^ y[i-1]);//conferir lógica
    }
    return result;
} //funcionando para strings digitadas não pelo usuário

size_t BinaryDistanceA(const string x, const string y, const size_t length){ //número de 1's que match nas duas strings
    size_t result{0};
    for(size_t i = 1; i <= length; ++i){
        if((x[i-1] == 1) && (y[i-1] == 1))
            result++;
    }
    return result;
}

size_t BinaryDistanceB(const string x, const string y, const size_t length){ //número de 1's na string x que não match na string y
    size_t result{0};
    for(size_t i = 1; i <= length; ++i){
        if((x[i-1] == 1) && (y[i-1] == 0))
            result++;
    }
    return result;
}

size_t BinaryDistanceC(const string x, const string y, const size_t length){ //número de 0's na string x que não match na string y
    size_t result{0};
    for(size_t i = 1; i <= length; ++i){
        if((x[i-1] == 0) && (y[i-1] == 1))
            result++;
    }
    return result;
}

size_t BinaryDistanceD(const string x, const string y, const size_t length){ //número de 0's que match nas duas strings
    size_t result{0};
    for(size_t i = 1; i <= length; ++i){
        if((x[i-1] == 0) && (y[i-1] == 1))
            result++;
    }
    return result;
}

double RusselRao(const size_t a, const size_t b, const size_t c, const size_t d){
    double f;
    f = (a / (a + b + c + d));
    return f;
}

double JacardNeedham(const size_t a, const size_t b, const size_t c){
    double f;
    f = (a / (a + b + c));
    return f;
}

double Kulzinski(const size_t a, const size_t b, const size_t c){
    double f;
    f = (a / (b + c + 1));
    return f;
}

double SokalMichener(const size_t a, const size_t b, const size_t c, const size_t d){
    double f;
    f = ((a + d) / (a + b + c + d));
    return f;
}

double RogersTanimoto(const size_t a, const size_t b, const size_t c, const size_t d){
    double f;
    f = ((a + d) / (a + d + (2 * (b + c))));
    return f;
}

double Yule(const size_t a, const size_t b, const size_t c, const size_t d){
    double f;
    f = (((a * d) - (b * c)) / ((a * d) + (b * c)));
    return f;
}

size_t editDistance(){ //recursivo

}
