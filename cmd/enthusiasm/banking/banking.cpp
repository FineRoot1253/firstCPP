//
// Created by 홍준근 on 2023/01/20.
//

#include "enthusiasm/banking/common/Runner.h"

int main(){
    BankServiceRunner runner = BankServiceRunner(BankService(AccountRepository()));
    runner.run();
}