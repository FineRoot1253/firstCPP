//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_VIEW_H
#define FIRSTCPP_VIEW_H

#include "enthusiasm/banking/infra/ViewModelEventListener.h"

class View: public ViewModelEventListener {
protected:
    // execute when view Entity not exist on view entity List; (only just one time)
    virtual void initState(){};
    virtual void render(){}
    virtual void dispose(){

    };
public:
    View(const ViewModelEventListener &viewModelEventListener)
            : ViewModelEventListener(viewModelEventListener) {
    };

    virtual ~View(){};

    void draw() {
        initState();
        render();
        dispose();
    };
    void update() override{
        draw();
    };
};


#endif //FIRSTCPP_VIEW_H
