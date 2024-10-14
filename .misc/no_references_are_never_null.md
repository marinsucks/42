[OG LINK](https://www.reddit.com/r/cpp/comments/80zm83/no_references_are_never_null/)



Many other languages made the fatal error of permitting null as valid for all reference types, where every non-builtin is a reference type and they have boxing around classes. Here's some psuedo-Java:

```cpp
class MyType {
  public void foo() {}
};

void my_fun(MyType instance) {
  instance.foo(); // <-- MAY THROW
}

void another_fun() {
  my_fun(null); // <-- explodes
}
```

This is semantically similar to the following C++:

```cpp
class MyType {
public:
  void foo() {}
}

void my_fun(MyType* instance) {
  __check_nonnull(instance); // <-- Check inserted by compiler
  instance->foo();
}

void another_fun() {
  my_fun(nullptr);
}
```

With implicitly nullable references, every single use of the reference is a candidate for a nullptr.

On the contrary, C++ affords the guarantee that a T& always refers to a valid T.

Of course, all of C++'s guarantees have a caveat: Every guarantee goes out the window if any part of a program contains undefined behavior.

Here's a common "C++ null reference" example that detractors provide:

```cpp
class MyClass {
public:
  void foo();
};

void do_thing(MyClass& inst) {
  inst.foo();
}

void other_thing() {
  MyClass* inst_ptr = nullptr;
  do_thing(*inst_ptr);
}
```

Of course, the fact that we dereference inst_ptr means the program behavior is undefined. The call inst.foo() is perfectly legal, and checking that &inst != nullptr is unnecessary.

In fact, the very expression &<anything> != nullptr is completely non-sensical. C++ guarantees that the builtin address-of operator& never returns nullptr. We even get a warning about it from GCC.

Saying "impossible thing might happen" is not useful. Imagine this code:

```cpp
class MyClass {
public:
  void foo();
};

class UnrelatedClass {
public:
  void foo();
}

void do_thing(MyClass& inst) {
  inst.foo();
}
```

Saying "inst might be a null reference" is equivalent to saying "inst might actually be an UnrelatedClass" because someone might do this:

```cpp
cppvoid garbage_fn() {
  UnrelatedClass garbage;
  do_thing(reinterpret_cast<MyClass&>(garbage));
}
```

Both cases are undefined, but for some reason, people still believe that null-references are a thing.


Edit to clarify:

I'm not saying that dereferencing null pointers never occurs in practice. What I'm really saying is that there is no use in worrying if a client has dereferenced a null pointer in order to fulfill a reference parameter on your API. There's no meaningful action that you can take. 