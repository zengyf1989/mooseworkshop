#include "MooseworkshopApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<MooseworkshopApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MooseworkshopApp::MooseworkshopApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MooseworkshopApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MooseworkshopApp::associateSyntax(_syntax, _action_factory);
}

MooseworkshopApp::~MooseworkshopApp()
{
}

// External entry point for dynamic application loading
extern "C" void MooseworkshopApp__registerApps() { MooseworkshopApp::registerApps(); }
void
MooseworkshopApp::registerApps()
{
  registerApp(MooseworkshopApp);
}

// External entry point for dynamic object registration
extern "C" void MooseworkshopApp__registerObjects(Factory & factory) { MooseworkshopApp::registerObjects(factory); }
void
MooseworkshopApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MooseworkshopApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MooseworkshopApp::associateSyntax(syntax, action_factory); }
void
MooseworkshopApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
