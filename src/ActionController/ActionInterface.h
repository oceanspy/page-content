#ifndef ACTIONINTERFACE_H
#define ACTIONINTERFACE_H

class ActionInterface {
public:
    virtual ~ActionInterface() = default;
    virtual void execute() = 0;
};

#endif //ACTIONINTERFACE_H
