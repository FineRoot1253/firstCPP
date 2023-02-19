//
// Created by 홍준근 on 2023/02/04.
//

#ifndef FIRSTCPP_VIEWENTITYFACTORY_H
#define FIRSTCPP_VIEWENTITYFACTORY_H

#include "ViewEntity.h"
#include "ViewEntityDefaultData.h"
#include "view_type.h"
#include "Exception.h"
#include "enthusiasm/banking/ui/includes/ViewID.h"
#include "constants.h"

class ViewEntityFactory{
public:
    ViewEntity<ViewID, ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>> createEmptyEntity(eViewType viewType){
        switch(viewType){
            case eViewType::MainMenu :
                return ViewEntity<ViewID, ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>>()
                .adder(ViewID(static_cast<const long>(viewType)),ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>());
            case eViewType::MakeAccountForm :
                return ViewEntity<ViewID, ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>>()
                        .adder(ViewID(static_cast<const long>(viewType)),ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>());
            case eViewType::DepositForm :
                return ViewEntity<ViewID, ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>>()
                        .adder(ViewID(static_cast<const long>(viewType)),ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>());
            case eViewType::WithdrawForm :
                return ViewEntity<ViewID, ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>>()
                        .adder(ViewID(static_cast<const long>(viewType)),ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>());
            case eViewType::UserListForm :
                return ViewEntity<ViewID, ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>>()
                        .adder(ViewID(static_cast<const long>(viewType)),ViewEntity<ViewEntityDefaultData,ViewEntityDefaultData>());
            default:
                throw SystemCallException(constants_ex_kr::EX_MSG_SYS_CAN_NOT_SWITCH_DEFAULT);
        }
    }
};
#endif //FIRSTCPP_VIEWENTITYFACTORY_H
