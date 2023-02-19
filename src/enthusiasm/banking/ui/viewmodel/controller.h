//
// Created by 홍준근 on 2023/02/12.
//

#ifndef FIRSTCPP_CONTROLLER_H
#define FIRSTCPP_CONTROLLER_H

// ViewManager [Root Subject]
//             - Views[extends Listener, 원칙적으론 MVVM에서는 1 View : N ViewModel이지만 다른 패턴등의 확장성을 고려해 N:M도 가능하게 구현]
//               View - ViewModel [extends Listener & Sub Subjects, View와 Stack Delegate 관계 -> 즉, View에 ViewModels가 포함된 형태, ViewModels는 컬렉션이나 배열 형태가 아닌 구조 클래스 각각임]
//                    - ViewModel
//                    - ViewModel
//                         ...
//
// 따라서, ViewManager는 Listener 컬렉션을 Views만 가져도 ViewModels는 딸려 가지는 형태가 되며 각 ViewModels의 Subject는 상속을 받는 형태이기 때문에 각각 다른 메모리를 차지하고 있다는 것을 명심해야함
// 자바로 따지면 같은 객체를 생성해도 내부적으로는 다른 메모리의 상속 객체를 지니고 있는건 당연한 것
// viewModel은 각각 같은 listenerList 포인터를 공유하고 있어 같은 viewList를 가지고 있다.
// 즉, 이렇게 되면 각 viewModel에서 특정 viewId를 update하는 과정은 상당히 까다로워질 수 있다. 수많은 for loop이 수반될 가능성이 높다.
// GrowableList는 무조건 전체 loop을 처음부터 돌게 구현되어있다.
// LinkedList Open probing HashTable로 만들었다면 아마 훨씬 빠르게 looping을 돌 수 있겠지만 이건 추후의 백로그로 남겨야할듯하다.

// Current notify process
// vm-> notify()
//  - 1) check View is loaded [call viewManager.isViewLoaded()]// 뷰 로드 확인
//  - 2) if not loaded yet, loadView [call loadView()] // 없으면 로드, 있으면 3)
//  - 3) for loop, find view to update and update, if can not find view, throw SystemException // for loop을 돌아서 뷰를 찾아 업데이트
//  - 4) after updated, call addLoadedView() -> this is big problem // 업데이트가 끝나면 addLoadView()
//       update하기전 callViewIdList를 먼저 add하는 이유는 update를 하는 동작에서 어떤 view를 업데이트 하는지 viewId를 찾기 위함,
//       loadViewIdList에 add를 update 하기 전에 하지 않고 update한 후 add 하는 이유는 어떤 비동기 동작이 뷰에 끼어들어있을지 모르기 때문

// problem 1) how to get to specific view?
// vm -> getTo()
// - 1) clear callViewIdList[call callViewIds.clear()] // 호출 뷰 리스트 클리어 [called 뷰는 지금 getTo의 목적지 뷰이기 때문]
// - 1) check View is loaded [call viewManager.isViewLoaded()] // 뷰 로드 확인
// - 2) if not loaded yet, loadView [call loadView()] // 없으면 로드, 있으면 4)
// - 3) listeners.get(listener.where(ViewID)).update(); // 목적지 뷰 update()
// - 4) addLoadedView() 호출

// problem 2) addLoadedView는 언제 호출해야하나?
// update시 cin로직이 존재하는 경우 무조건 addLoadedView는 나중에 호출된다.
// 즉, update() 호출직전에 호출하는게 나아보이며 hook에 공통으로 넣고싶지만 힘들어보인다.

// ViewModel - Controller[current, ViewManager]
//           - loadView
//                       - 1) check is already loaded view in loadedViewList
//                       - 2) createView If not loaded, if already loaded done on 1)
//                       - 3) add callView the viewId on callViewList
//           - getTo
//                       - 1) callViewIdList clear
//                       - 2) call loadView
//                       - 3) call notify [must be add viewId on loadedViewList after viewModel notify!!]
//



// ViewManger - ViewMap - {View, View, ...}

#endif //FIRSTCPP_CONTROLLER_H