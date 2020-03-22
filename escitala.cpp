//
//  escitala.cpp
//  ED3_Escitala
//
//  Created by Alexander Arturo Baylon Ibanez on 3/22/15.
//  Copyright (c) 2015 Alexander Arturo Baylon Ibanez. All rights reserved.
//

#include "escitala.h"


etl::etl(int c,string f)
{
    clave = c;
    frase = f;
    tamFrase    = int(frase.size());
    resto       = modulo(tamFrase,clave);
    if (resto == 0) bloques = tamFrase / clave;
    else            bloques = (tamFrase / clave) + 1;
    for (int i=0; i<clave-resto; i++)
        frase += 'x';
    tamFrase    = int(frase.size());
}

etl::etl(string m,int c)
{
    crip     = m;
    clave    = c;
    tamFrase = int(crip.size());
    bloques  = tamFrase / clave;
}


void etl::print()
{
    cout << "clave: " << clave << endl;
    cout << "frase: " << frase << endl;
    cout << "bloques: " << bloques << endl;
    cout << "tam frase: " << tamFrase << endl;
    cout << "resto: " << resto << endl;
}

string etl::encriptar()
{
    for (int j=0; j<clave; j++) {
        for (int k=j; k<tamFrase; k+=clave)
            crip += frase[k];
        cout << "bloque " << j << " :" << crip << endl;
    }
    return crip;
}


string etl::descencriptar()
{
    for (int i=0; i<bloques; i++) {
        for (int j=i; j<tamFrase; j+=bloques)
            decrip += crip[j];
        cout << "bloque " << i << " :" << decrip << endl;
    }
    tamFrase--;
    for (; tamFrase > 0; tamFrase--) {
        if (decrip[tamFrase]=='x')
            decrip.pop_back();
    }
    cout << "resto: " << resto << endl;
    return decrip;
}

int etl::modulo(int a,int b)
{
    return (a>0) ? a - ((a/b) * b) : abs(((a/b)-1) * b) + a;
}

