//
// Created by 홍준근 on 2023/01/18.
//

#ifndef FIRSTCPP_CONSTANTS_H
#define FIRSTCPP_CONSTANTS_H
namespace constants{
    constexpr int ACCOUNT_LIMIT = 10;

    constexpr int LISTENERS_LIMIT=100;
    constexpr int HDATA_GROUP_INIT_SIZE=10;
    constexpr int HDATA_GROUP_ADD_STEP_SIZE=5;

    namespace utils{
        constexpr char TXT_DEFAULT[] = "";

        constexpr char TXT_ERROR_PROPERTY_KEY_IS_ERROR[] = "isError";
        constexpr char TXT_ERROR_PROPERTY_KEY_CONTENT[] = "content";

        constexpr char TXT_ERROR_PROPERTY_VALUE_IS_ERROR_TRUE[] = "true";
    }

    namespace txt_kr{
        constexpr char TXT_INPUT_ACCOUNT_ID[] = "계좌ID: ";
        constexpr char TXT_INPUT_CUSTOMER_NAME[] = "이 름: ";
        constexpr char TXT_INPUT_DEPOSIT[] = "입금액: ";
        constexpr char TXT_INPUT_WITHDRAW[] = "출금액: ";
        constexpr char TXT_INPUT_LEFT[] = "잔액: ";
    }

    namespace ex_kr{
        constexpr char EX_MSG_COMMON[] = "알 수 없는 이유로 인해 예외가 발생했습니다.";

        constexpr char EX_MSG_SYS_STOP[] = "프로그램 종료 요청";
        constexpr char EX_MSG_SYS_ILLEGAL_INPUT[] = "처리 불가능한 입력입니다.";
        constexpr char EX_MSG_SYS_OOB[] = "현재 배열이 접근 불가능한 상태입니다.";
        constexpr char EX_MSG_SYS_CAN_NOT_FOUND_ELEMENT[] = "해당 요소를 찾을 수 없습니다.";
        constexpr char EX_MSG_SYS_CAN_NOT_SWITCH_DEFAULT[] = "여기는 오면 안되는 로직입니다.";

        constexpr char EX_MSG_VIEW_ENTITY_DUPLICATE[] = "이미 추가한 ViewEntity입니다.";

        constexpr char EX_MSG_ACCOUNT[] = "계정관련 이유로 예외가 발생했습니다.";

        constexpr char EX_MSG_DEPOSIT[] = "입금 불가능한 액수입니다.\n";
        constexpr char EX_MSG_DEPOSIT_AMOUNT[] = "입금액: ";

        constexpr char EX_MSG_WITHDRAW[] = "출금 불가능한 액수 입니다.\n";
        constexpr char EX_MSG_WITHDRAW_NOT_ENOUGH[] = "잔고가 부족해 출금이 불가능 합니다.\n";
        constexpr char EX_MSG_WITHDRAW_BALANCE[] = "현재 잔고: ";
        constexpr char EX_MSG_WITHDRAW_AMOUNT[] = "출금액: ";
    }

    namespace err_kr{
        constexpr char ERR_MSG_COMMON[] = "알 수 없는 이유로 인해 에러가 발생했습니다.";
        constexpr char ERR_MSG_NO_ERROR[] = "";

        constexpr char ERR_MSG_ACCOUNT_ID_NOT_FOUND[] = "일치하는 ACCOUNT ID가 없음";
        constexpr char ERR_MSG_ACCOUNT_ID_DUPLICATED[] = "중복된 ACCOUNT ID입니다.";

        constexpr char ERR_MSG_ELEMENT_NOT_FOUND[] = "없는 요소 입니다.";
        constexpr char ERR_MSG_ELEMENT_DUPLICATED[] = "이미 있는 요소 입니다.";

        constexpr char ERR_MSG_SAVE_INPUT_ERROR_LE[] = "0보다 작거나 같은 수";
        constexpr char ERR_MSG_SAVE_FAILURE[] = "Input 저장 실패";

        constexpr char EX_MSG_WITHDRAW_OVER[] = "너무 많은 액수를 출금";

    }

}

#endif //FIRSTCPP_CONSTANTS_H
