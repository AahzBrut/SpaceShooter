#include "EntryPoint.h"


SpaceShooter::Application *GetApplication() {
    return new SpaceShooter::Application();
}


int main() {
    const auto application = GetApplication();
    application->Run();
    delete application;

    return 0;
}
