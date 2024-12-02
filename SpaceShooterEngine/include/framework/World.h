#pragma once


namespace SpaceShooter {
    class  Application;
    // ReSharper disable once CppClassCanBeFinal
    class World {
    public:
        explicit World(Application *application);
        virtual ~World() = default;

        void InternalInitialize();
        void InternalUpdate(float deltaTime);

    private:
        Application *application;
        bool initialized;

        virtual void Initialize() {}
        virtual void Update(float deltaTime) {}
    };
}
