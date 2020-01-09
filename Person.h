#ifndef PERSON_H
#define PERSON_H

#include <QtCore>

class Person{
  QString firstName;
  QString lastName;

public:
  Person(QString fn, QString ln);

  QString getFirstName () const;

  QString getLastName() const;

};

#endif
