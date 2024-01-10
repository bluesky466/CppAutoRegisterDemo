# 参数

- DDEPENDENT\_MODE : 依赖模式,SOURCE为源码依赖,STATIC为静态库依赖,SHARED为动态库依赖
- EN\_SHARED\_FROM\_THIS : 支持std::shared\_from\_this,默认为ON支持

# 源码依赖,支持std::shared\_from\_this

> cd build
>
> cmake .. -DDEPENDENT_MODE=SOURCE -DEN_SHARED_FROM_THIS=ON

```
./Demo
kGlobalStr :
GLOBAL_STR : GLOBAL_STR
ComponentA::Init()
ComponentB::Init() - 0x600001c04288
```

# 静态库依赖,支持std::shared\_from\_this

> cd build
>
> cmake .. -DDEPENDENT_MODE=STATIC -DEN_SHARED_FROM_THIS=ON

```
./Demo
kGlobalStr :
GLOBAL_STR : GLOBAL_STR
Unknown : ComponentA
ComponentB::Init() - 0x60000062c288
```

# 动态库依赖,支持std::shared\_from\_this

> cd build
>
> cmake .. -DDEPENDENT_MODE=SHARED -DEN_SHARED_FROM_THIS=ON

```
kGlobalStr : GlobalStr
GLOBAL_STR : GLOBAL_STR
ComponentA::Init()
ComponentB::Init() - 0x600002298288
```

# 源码依赖,不支持std::shared\_from\_this

> cd build
>
> cmake .. -DDEPENDENT_MODE=SOURCE -DEN_SHARED_FROM_THIS=OFF

```
./Demo
kGlobalStr :
GLOBAL_STR : GLOBAL_STR
ComponentA::Init()
libc++abi: terminating with uncaught exception of type std::__1::bad_weak_ptr: bad_weak_ptr
ComponentB::Init() - [1]    94040 abort      ./Demo
```

# 静态库依赖,不支持std::shared\_from\_this

> cd build
>
> cmake .. -DDEPENDENT_MODE=STATIC -DEN_SHARED_FROM_THIS=OFF

```
./Demo
kGlobalStr :
GLOBAL_STR : GLOBAL_STR
Unknown : ComponentA
libc++abi: terminating with uncaught exception of type std::__1::bad_weak_ptr: bad_weak_ptr
ComponentB::Init() - [1]    95607 abort      ./Demo
```

# 动态库依赖,不支持std::shared\_from\_this

> cd build
>
> cmake .. -DDEPENDENT_MODE=SHARED -DEN_SHARED_FROM_THIS=OFF

```
./Demo
kGlobalStr : GlobalStr
GLOBAL_STR : GLOBAL_STR
ComponentA::Init()
libc++abi: terminating with uncaught exception of type std::__1::bad_weak_ptr: bad_weak_ptr
ComponentB::Init() - [1]    97874 abort      ./Demo
```