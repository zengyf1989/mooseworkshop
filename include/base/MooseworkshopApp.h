#ifndef MOOSEWORKSHOPAPP_H
#define MOOSEWORKSHOPAPP_H

#include "MooseApp.h"

class MooseworkshopApp;

template<>
InputParameters validParams<MooseworkshopApp>();

class MooseworkshopApp : public MooseApp
{
public:
  MooseworkshopApp(InputParameters parameters);
  virtual ~MooseworkshopApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSEWORKSHOPAPP_H */
