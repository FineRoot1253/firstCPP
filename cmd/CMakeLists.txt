add_executable(enthusiasm_racing_car_run enthusiasm/struct/RacingCar.cpp)
add_executable(enthusiasm_fruit_1_run ../cmd/enthusiasm/class/FruitSim_1.cpp)
add_executable(enthusiasm_car_run enthusiasm/class/car.cpp)
add_executable(enthusiasm_point_run enthusiasm/class/Point.cpp)
add_executable(enthusiasm_Encaps_1_run enthusiasm/class/Encaps_1.cpp)
add_executable(enthusiasm_Encaps_2_run enthusiasm/class/Encaps_2.cpp)
add_executable(enthusiasm_Constructor_1_run enthusiasm/class/Constructor_1.cpp)
add_executable(enthusiasm_PrivateConstructor_run enthusiasm/class/PrivateConstructor.cpp)
add_executable(enthusiasm_Destructor_run enthusiasm/class/Destructor.cpp)
add_executable(enthusiasm_ObjArr_run enthusiasm/class/ObjArr.cpp)
add_executable(enthusiasm_ObjPtrArr_run enthusiasm/class/ObjPtrArr.cpp)
add_executable(enthusiasm_SelfRef_run enthusiasm/class/SelfRef.cpp)
add_executable(enthusiasm_ClassInit_run enthusiasm/class/ClassInit.cpp)
add_executable(enthusiasm_ShalloCopyError_run enthusiasm/class/ShalloCopyError.cpp)
add_executable(enthusiasm_PassObjectCopyConstructor_run enthusiasm/class/PassObjectCopyConstructor.cpp)
add_executable(enthusiasm_ReturnObjectCopyConstructor_run enthusiasm/class/ReturnObjectCopyConstructor.cpp)
add_executable(enthusiasm_IKnowTempObject_run enthusiasm/class/IKnowTempObject.cpp)
add_executable(enthusiasm_ReturnObjectDeadTime_run enthusiasm/class/ReturnObjectDeadTime.cpp)

add_executable(enthusiasm_ConstObject_run enthusiasm/friend/ConstObject.cpp)
add_executable(enthusiasm_ConstOverloading_run enthusiasm/friend/ConstOverloading.cpp)

add_executable(enthusiasm_Banking_run enthusiasm/banking/banking.cpp)

target_link_libraries(
        enthusiasm_racing_car_run
        RacingCar
)
target_link_libraries(
        enthusiasm_car_run
        Car
)
target_link_libraries(
        enthusiasm_fruit_1_run
        FruitSeller
        FruitBuyer
)

target_link_libraries(
        enthusiasm_point_run
        Rectangle
        Enthusiasm_Point
)

target_link_libraries(
        enthusiasm_Encaps_1_run
        Encaps_1
)

target_link_libraries(
        enthusiasm_Encaps_2_run
        Encaps_2
)

target_link_libraries(
        enthusiasm_Constructor_1_run
        Constructor_1
)

target_link_libraries(
        enthusiasm_Destructor_run
        Destructor
)

target_link_libraries(
        enthusiasm_ObjArr_run
        ObjArr
)

target_link_libraries(
        enthusiasm_ObjPtrArr_run
        ObjArr
)

target_link_libraries(
        enthusiasm_SelfRef_run
        SelfRef
)

target_link_libraries(
        enthusiasm_Banking_run
        AccountRepository
        BankService
        Account_Entity
        NormalAccount_Entity
        HighCreditAccount_Entity
        MainMenu
        MakeAccountForm
        DepositForm
        UserListForm
        WithdrawForm
        Event_Provider
        ViewModelEventListener
        MainMenu_ViewModel
        MakeAccountForm_ViewModel
        DepositForm_ViewModel
        WithdrawForm_ViewModel
        UserListForm_ViewModel
)

add_executable(enthusiasm_MyFriendClass_run enthusiasm/friend/MyFriendClass.cpp)
add_executable(enthusiasm_MyFriendFunction_run enthusiasm/friend/MyFriendFunction.cpp)
add_executable(enthusiasm_CComStatic_run enthusiasm/friend/CComStatic.cpp enthusiasm/friend/CComStatic.cpp)
add_executable(enthusiasm_NeedGlobal_run enthusiasm/friend/NeedGlobal.cpp)
add_executable(enthusiasm_StaticMember_run enthusiasm/friend/StaticMember.cpp)
add_executable(enthusiasm_PublicStaticMember_run enthusiasm/friend/PublicStaticMember.cpp)
add_executable(enthusiasm_StaticMemberFunction_run enthusiasm/friend/StaticMemberFunction.cpp)
add_executable(enthusiasm_ConstStaticMember_run enthusiasm/friend/ConstStaticMember.cpp)
add_executable(enthusiasm_Mutable_run enthusiasm/friend/Mutable.cpp)
add_executable(enthusiasm_EmployeeManager1_run enthusiasm/inheritance/EmployeeManager1.cpp)
add_executable(enthusiasm_UnivStudentinheri_run enthusiasm/inheritance/UnivStudentinheri.cpp)
add_executable(enthusiasm_DerivCreOrder_run enthusiasm/inheritance/DerivCreOrder.cpp)
add_executable(enthusiasm_DerivDestOrder_run enthusiasm/inheritance/DerivDestOrder.cpp)
add_executable(enthusiasm_DestModel_run enthusiasm/inheritance/DestModel.cpp)
add_executable(enthusiasm_ProtectedHeri_run enthusiasm/inheritance/ProtectedHeri.cpp)
add_executable(enthusiasm_ISAInheritance_run enthusiasm/inheritance/ISAInheritance.cpp)
add_executable(enthusiasm_HASInheritance_run enthusiasm/inheritance/HASInheritance.cpp)
add_executable(enthusiasm_HASComposite_run enthusiasm/inheritance/HASComposite.cpp)
add_executable(enthusiasm_ObjectPointer_run enthusiasm/polymorphism/ObjectPointer.cpp)
add_executable(enthusiasm_EmployeeManager2_run enthusiasm/polymorphism/EmployeeManager2.cpp)
add_executable(enthusiasm_EmployeeManager3_run enthusiasm/polymorphism/EmployeeManager3.cpp)
add_executable(enthusiasm_FunctionOverride_run enthusiasm/polymorphism/FunctionOverride.cpp)
add_executable(enthusiasm_FunctionVirtualOverride_run enthusiasm/polymorphism/FunctionVirtualOverride.cpp)
add_executable(enthusiasm_EmployeeManager4_run enthusiasm/polymorphism/EmployeeManager4.cpp)
add_executable(enthusiasm_VirtualDestructor_run enthusiasm/polymorphism/VirtualDestructor.cpp)
add_executable(enthusiasm_RealObjUnder1_run enthusiasm/polymorphism/RealObjUnder1.cpp)
add_executable(enthusiasm_RealObjUnder2_run enthusiasm/polymorphism/RealObjUnder2.cpp)
add_executable(enthusiasm_VitualInternal_run enthusiasm/polymorphism/VitualInternal.cpp)
add_executable(enthusiasm_MultiInheri1_run enthusiasm/polymorphism/MultiInheri1.cpp)
add_executable(enthusiasm_MultiInheri2_run enthusiasm/polymorphism/MultiInheri2.cpp)
add_executable(enthusiasm_MultiInheri3_run enthusiasm/polymorphism/MultiInheri3.cpp)
add_executable(enthusiasm_FirstOperationOverloading_run enthusiasm/operator/FirstOperationOverloading.cpp)
add_executable(enthusiasm_OverloadingOperation_run enthusiasm/operator/OverloadingOperation.cpp)
add_executable(enthusiasm_GFunctionOverloading_run enthusiasm/operator/GFunctionOverloading.cpp)
add_executable(enthusiasm_OneOpnOverloading_run enthusiasm/operator/OneOpnOverloading.cpp)
add_executable(enthusiasm_PostOpndOverloading_run enthusiasm/operator/PostOpndOverloading.cpp)
add_executable(enthusiasm_PointMultipleOverloading_run enthusiasm/operator/PointMultipleOverloading.cpp)
add_executable(enthusiasm_CommuMultipleOperation_run enthusiasm/operator/CommuMultipleOperation.cpp)
add_executable(enthusiasm_ConsoleOutput_run enthusiasm/operator/ConsoleOutput.cpp)
add_executable(enthusiasm_IterateConsoleOutput_run enthusiasm/operator/IterateConsoleOutput.cpp)
add_executable(enthusiasm_PointConsoleOutput_run enthusiasm/operator/PointConsoleOutput.cpp)
add_executable(enthusiasm_FirstOperationOverloading1_run enthusiasm/operator/FirstOperationOverloading1.cpp)
add_executable(enthusiasm_AssignShallowCopyError_run enthusiasm/operator/AssignShallowCopyError.cpp)
add_executable(enthusiasm_InheritAssignOperation_run enthusiasm/operator/InheritAssignOperation.cpp)
add_executable(enthusiasm_ImproveInit_run enthusiasm/operator/ImproveInit.cpp)
add_executable(enthusiasm_ArrayClass_run enthusiasm/operator/ArrayClass.cpp)
add_executable(enthusiasm_StableConstArrayProb_run enthusiasm/operator/StableConstArrayProb.cpp)
add_executable(enthusiasm_StablePointObjArray_run enthusiasm/operator/StablePointObjArray.cpp)
add_executable(enthusiasm_StablePointPtrArray_run enthusiasm/operator/StablePointPtrArray.cpp)
add_executable(enthusiasm_NewDeleteOverloading_run enthusiasm/operator/NewDeleteOverloading.cpp)
add_executable(enthusiasm_ArrayNewDeleteOverloading_run enthusiasm/operator/ArrayNewDeleteOverloading.cpp)
add_executable(enthusiasm_PointerOperatorOverloading_run enthusiasm/operator/PointerOperatorOverloading.cpp)
add_executable(enthusiasm_SmartPointer_run enthusiasm/operator/SmartPointer.cpp)
add_executable(enthusiasm_Functor_run enthusiasm/operator/Functor.cpp)
add_executable(enthusiasm_SortFunctor_run enthusiasm/operator/SortFunctor.cpp)
add_executable(enthusiasm_ConvToObject_run enthusiasm/operator/ConvToObject.cpp)
add_executable(enthusiasm_ConvToPrimitive_run enthusiasm/operator/ConvToPrimitive.cpp)
add_executable(enthusiasm_STDString_run enthusiasm/string/STDString.cpp)
add_executable(enthusiasm_StringClass_run enthusiasm/string/StringClass.cpp)
target_link_libraries(
        enthusiasm_StringClass_run
        Custom_String
)
add_executable(enthusiasm_AddFunctionTemplate_run enthusiasm/template/AddFunctionTemplate.cpp)
add_executable(enthusiasm_TwoTypeAddFunction_run enthusiasm/template/TwoTypeAddFunction.cpp)
add_executable(enthusiasm_PrimitiveFunctionTemplate_run enthusiasm/template/PrimitiveFunctionTemplate.cpp)
add_executable(enthusiasm_NeedSpecialFunctionTemplate_run enthusiasm/template/NeedSpecialFunctionTemplate.cpp)
add_executable(enthusiasm_SpecialFunctionTemplate_run enthusiasm/template/SpecialFunctionTemplate.cpp)
add_executable(enthusiasm_PointClassTemplate_run enthusiasm/template/PointClassTemplate.cpp)
add_executable(enthusiasm_PointClassTemplateFuncDef_run enthusiasm/template/PointClassTemplateFuncDef.cpp)
add_executable(enthusiasm_PointMain_run enthusiasm/template/PointMain.cpp)
add_executable(enthusiasm_BoundArrayMain_run enthusiasm/template/BoundArrayMain.cpp)
target_link_libraries(
        enthusiasm_PointMain_run
        PointTemplate
)
target_link_libraries(
        enthusiasm_BoundArrayMain_run
        Point_Temp
)
add_executable(enthusiasm_PointTemplateFriendFunction_run enthusiasm/template/PointTemplateFriendFunction.cpp)
add_executable(enthusiasm_ClassTemplateSpecialization_run enthusiasm/template/ClassTemplateSpecialization.cpp)
add_executable(enthusiasm_ClassTemplatePartialSpecialization_run enthusiasm/template/ClassTemplatePartialSpecialization.cpp)
add_executable(enthusiasm_NonTypeTemplateParam_run enthusiasm/template/NonTypeTemplateParam.cpp)
add_executable(enthusiasm_TemplateParamDefaultValue_run enthusiasm/template/TemplateParamDefaultValue.cpp)
add_executable(enthusiasm_FunctionTemplateStaticVar_run enthusiasm/template/FunctionTemplateStaticVar.cpp)
add_executable(enthusiasm_ClassTemplateStaticMem_run enthusiasm/template/ClassTemplateStaticMem.cpp)
add_executable(enthusiasm_UnhandlingException_run enthusiasm/exception/UnhandlingException.cpp)
add_executable(enthusiasm_HandlingExceptionUseIf_run enthusiasm/exception/HandlingExceptionUseIf.cpp)
add_executable(enthusiasm_HandlingExceptionTryCatch_run enthusiasm/exception/HandlingExceptionTryCatch.cpp)
add_executable(enthusiasm_PassException_run enthusiasm/exception/PassException.cpp)
add_executable(enthusiasm_DiffHandingPosition_run enthusiasm/exception/DiffHandingPosition.cpp)
add_executable(enthusiasm_StackUnwinding_run enthusiasm/exception/StackUnwinding.cpp)
add_executable(enthusiasm_CatchList_run enthusiasm/exception/CatchList.cpp)
add_executable(enthusiasm_ATMSim_run enthusiasm/exception/ATMSim.cpp)
add_executable(enthusiasm_ATMSim2_run enthusiasm/exception/ATMSim2.cpp)
add_executable(enthusiasm_CatchFlow_run enthusiasm/exception/CatchFlow.cpp)
add_executable(enthusiasm_BadAlloc_run enthusiasm/exception/BadAlloc.cpp)
add_executable(enthusiasm_ReThrow_run enthusiasm/exception/ReThrow.cpp)
add_executable(enthusiasm_PowerfullCasting_run enthusiasm/casting/PowerfullCasting.cpp)
add_executable(enthusiasm_DynamicCasting_run enthusiasm/casting/DynamicCasting.cpp)
add_executable(enthusiasm_StaticCasting_run enthusiasm/casting/StaticCasting.cpp)
add_executable(enthusiasm_ConstCasting_run enthusiasm/casting/ConstCasting.cpp)
add_executable(enthusiasm_ReinterpretCasting_run enthusiasm/casting/ReinterpretCasting.cpp)
add_executable(enthusiasm_PolymorphismDynamicCasting_run enthusiasm/casting/PolymorphismDynamicCasting.cpp)
add_executable(enthusiasm_PolymorphicStableCasting_run enthusiasm/casting/PolymorphicStableCasting.cpp)
add_executable(enthusiasm_DynamicBadCastRef_run enthusiasm/casting/DynamicBadCastRef.cpp)
add_executable(enthusiasm_ReferenceAttribute_run enthusiasm/polymorphism/ReferenceAttribute.cpp)
add_executable(enthusiasm_LinearSearch_run enthusiasm/algorithm/LinearSearch.cpp)
add_executable(enthusiasm_BinarySearch_run enthusiasm/algorithm/BinarySearch.cpp)
add_executable(enthusiasm_BSWorstOpCount_run enthusiasm/algorithm/BSWorstOpCount.cpp)
add_executable(enthusiasm_RecursiveFunc_run enthusiasm/recursive/RecursiveFunc.cpp)
add_executable(enthusiasm_RecursiveFactorial_run enthusiasm/recursive/RecursiveFactorial.cpp)
add_executable(enthusiasm_FibonacciFunc_run enthusiasm/recursive/FibonacciFunc.cpp)
add_executable(enthusiasm_RecursiveBinarySearch_run enthusiasm/recursive/RecursiveBinarySearch.cpp)
add_executable(enthusiasm_HanoiTower_run enthusiasm/recursive/HanoiTower.cpp)
add_executable(enthusiasm_ListMain_run enthusiasm/linked_list/ListMain.cpp)
add_executable(enthusiasm_PointListMain_run enthusiasm/linked_list/PointListMain.cpp)
target_link_libraries(
        enthusiasm_PointListMain_run
        Point_For_Linked_List
)
add_executable(enthusiasm_ArrayRead_run enthusiasm/linked_list/ArrayRead.cpp)
add_executable(enthusiasm_LinkedRead_run enthusiasm/linked_list/LinkedRead.cpp)
add_executable(enthusiasm_DLinkedListMain_run enthusiasm/linked_list/DLinkedListMain.cpp)
add_executable(enthusiasm_DLinkedListSortMain_run enthusiasm/linked_list/DLinkedListSortMain.cpp)
add_executable(enthusiasm_CLinkedListMain_run enthusiasm/linked_list/CLinkedListMain.cpp)
add_executable(enthusiasm_DBLinkedListMain_run enthusiasm/linked_list/DBLinkedListMain.cpp)
add_executable(enthusiasm_DBDLinkedListMain_run enthusiasm/linked_list/DBDLinkedListMain.cpp)
add_executable(enthusiasm_ArrayBaseStack_run enthusiasm/stack/ArrayBaseStack.cpp)
add_executable(enthusiasm_ListBaseStack_run enthusiasm/stack/ListBaseStack.cpp)
add_executable(enthusiasm_InfixToPostfix_run enthusiasm/stack/InfixToPostfix.cpp)
add_executable(enthusiasm_PostCalculatorMain_run enthusiasm/stack/PostCalculatorMain.cpp)
target_link_libraries(
        enthusiasm_InfixToPostfix_run
        ExpressionConvertor
)
target_link_libraries(
        enthusiasm_PostCalculatorMain_run
        ExpressionConvertor
)
add_executable(enthusiasm_CircularQueue_run enthusiasm/queue/CircularQueue.cpp)
add_executable(enthusiasm_ListBaseQueue_run enthusiasm/queue/ListBaseQueue.cpp)
add_executable(enthusiasm_HamburgerSim_run enthusiasm/queue/HamburgerSim.cpp)

add_executable(enthusiasm_Deque_run enthusiasm/queue/Deque.cpp)
add_executable(broadcastUV_Clang_ch1_hellosky_run broadcastUV/Clang/ch1/hellohong.c)
add_executable(broadcastUV_Clang_ch1_hello_run broadcastUV/Clang/ch1/hello.c)
add_executable(broadcastUV_Clang_ch1_multiply_run broadcastUV/Clang/ch1/multiply.c)
add_executable(broadcastUV_Clang_ch1_sizeof_run broadcastUV/Clang/ch2/sizeof.c)
add_executable(broadcastUV_Clang_ch1_circle_area_run broadcastUV/Clang/ch2/circle_area.c)
add_executable(broadcastUV_Clang_ch1_exam2-3_run broadcastUV/Clang/ch2/exam2-3.c broadcastUV/Clang/ch2/exam2-3.h)
