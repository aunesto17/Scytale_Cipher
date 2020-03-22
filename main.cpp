//
//  main.cpp
//  ED3_Escitala
//
//  Created by Alexander Arturo Baylon Ibanez on 3/22/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//



#include "escitala.h"


int main(int argc, const char * argv[]) {
    
    int clave = 5;
    string msj = "miamigaanamariacuadrosprofesora";
    
    
    etl prueba(clave,msj);
    
    prueba.print();
    
    string encrip = prueba.encriptar();
    cout << encrip << endl;
    //cout << abs((-255/11)-1) << endl;
    cout << encrip.size() << endl;
    
    etl prueba1(encrip,clave);
    
    string decrip = prueba1.descencriptar();
    cout << decrip << endl;
    
    
    return 0;
}
