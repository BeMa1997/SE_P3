#include "Person.h"

Person::Person(QString fn, QString ln) : firstName(fn), lastName(ln){}

QString Person::getFirstName () const { return firstName; }

QString Person::getLastName () const { return lastName; }
