//
// Versuch 04: Einführung Klasse
/**
Praktikum Informatik 1 MMXXII
 *
 * @file Vektor.h
 *Inhalt: Headerdatei der Klasse Vektor
 * Beinhaltet die Klasse Vektor und die Definitionen davon
 */



/**
 * Vektor - Basisklasse fuer 3d vektor.<BR>
 * Klasse fuer Vektoren und zugehorigen Funktionen
 */
#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

class Vektor
{
   public:
    Vektor(double x, double y, double z);
    ~Vektor();

    void ausgabe() const;
    Vektor sub(const Vektor& input) const;
    double laenge() const;
    double skalarProd(const Vektor& input) const;
    double winkel(const Vektor& input) const;
    void rotiereUmZ(const double rad);
    
   private:
    double x;
    double y;
    double z;

};

#endif
