namespace hal_impl {

template<typename T>
class RegisterSet {
 public:
  constexpr explicit RegisterSet(uintptr_t address) :
    address_ {address}
  {
  }

  T& operator*() const noexcept {
    return *reinterpret_cast<T*>(address_);
  }

  T* operator->() const noexcept {
    return reinterpret_cast<T*>(address_);
  }

 private:
  uintptr_t const address_;
};

}  // namespace hal_impl
