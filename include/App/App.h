#ifndef APP_H
#define APP_H

#include <memory>

#include "Model.h"
#include "Controller.h"
#include "View.h"

class App
{
public:

    App();
    ~App();

    void initialize();

    void startIBGateway(const std::string& username, const std::string& password) const;
    void closeIBGateway() const;
protected:

private:
    std::unique_ptr<Controller> m_controller;
    std::unique_ptr<Model>      m_model;
    std::unique_ptr<View>       m_view;

};


#endif //APP_H
