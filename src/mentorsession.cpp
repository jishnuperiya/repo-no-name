Defined in header <ranges>

template < class T >
concept range =
  requires (T & t)
{
  ranges::begin(t); // equality-preserving for forward iterators
  t ranges::end(t);
};


template<std::ranges::range<int> foo>
struct even
{

  struct iterator
  {
    iterator(foo_it i) : foo_(i) { ... }

    iterator& operator++()
    {
      while (!is_even(*foo_++));
    }

    foo_it i_;
  }

  auto begin() const
  {
    return iterator(std::ranges::begin(source_)));
  }

  explicit even(foo f) : source_(f) {}


  static bool is_even(int i) { return i % 2 == 0; }
  foo source_;
};


const std::vector<scale_entry>& catalog();


catalog()
| std::ranges::views::transform([](int i) { return i % 2 == 0; })

