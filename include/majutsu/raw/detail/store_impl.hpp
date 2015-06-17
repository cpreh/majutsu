//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_RAW_DETAIL_STORE_IMPL_HPP_INCLUDED
#define MAJUTSU_RAW_DETAIL_STORE_IMPL_HPP_INCLUDED

#include <majutsu/raw/detail/store_decl.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	typename Alloc
>
majutsu::raw::detail::store<
	T,
	Alloc
>::store(
	allocator_type const &_alloc
)
:
	alloc_(
		_alloc
	),
	data_(
		nullptr
	),
	data_end_(
		nullptr
	),
	cap_(
		nullptr
	)
{
}

template<
	typename T,
	typename Alloc
>
majutsu::raw::detail::store<
	T,
	Alloc
>::store(
	size_type const _size,
	allocator_type const &_alloc
)
:
	alloc_(
		_alloc
	),
	data_(
		alloc_.allocate(
			_size
		)
	),
	data_end_(
		data_ + _size
	),
	cap_(
		data_end_
	)
{
}

template<
	typename T,
	typename Alloc
>
majutsu::raw::detail::store<
	T,
	Alloc
>::store(
	store const &_other
)
:
	alloc_(
		_other.alloc_
	),
	data_(
		alloc_.allocate(
			_other.size()
		)
	),
	data_end_(
		data_ + _other.size()
	),
	cap_(
		data_end_
	)
{
	std::copy(
		_other.data(),
		_other.data_end(),
		this->data()
	);
}

template<
	typename T,
	typename Alloc
>
majutsu::raw::detail::store<
	T,
	Alloc
>::store(
	store &&_other
)
:
	alloc_(
		_other.alloc_
	),
	data_(
		_other.data_
	),
	data_end_(
		_other.data_end_
	),
	cap_(
		_other.cap_
	)
{
	_other.data_ = nullptr;

	_other.data_end_ = nullptr;

	_other.cap_ = nullptr;
}

template<
	typename T,
	typename Alloc
>
majutsu::raw::detail::store<
	T,
	Alloc
> &
majutsu::raw::detail::store<
	T,
	Alloc
>::operator=(
	store const &_other
)
{
	if(
		this == &_other
	)
		return
			*this;

	this->deallocate();

	data_ = alloc_.allocate(_other.size());

	data_end_ = data_ + _other.size();

	cap_ = data_end_;

	std::copy(
		_other.data(),
		_other.data_end(),
		this->data()
	);

	return
		*this;
}

template<
	typename T,
	typename Alloc
>
majutsu::raw::detail::store<
	T,
	Alloc
> &
majutsu::raw::detail::store<
	T,
	Alloc
>::operator=(
	store &&_other
)
{
	std::swap(
		data_,
		_other.data_
	);

	std::swap(
		data_end_,
		_other.data_end_
	);

	std::swap(
		cap_,
		_other.cap_
	);

	return
		*this;
}

template<
	typename T,
	typename Alloc
>
majutsu::raw::detail::store<
	T,
	Alloc
>::~store()
{
	this->deallocate();
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::size_type
majutsu::raw::detail::store<
	T,
	Alloc
>::size() const
{
	return
		fcppt::cast::to_unsigned(
			std::distance(
				this->begin(),
				this->end()
			)
		);
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::size_type
majutsu::raw::detail::store<
	T,
	Alloc
>::capacity() const
{
	return
		fcppt::cast::to_unsigned(
			cap_ - data_
		);
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::pointer
majutsu::raw::detail::store<
	T,
	Alloc
>::data()
{
	return data_;
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::const_pointer
majutsu::raw::detail::store<
	T,
	Alloc
>::data() const
{
	return data_;
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::pointer
majutsu::raw::detail::store<
	T,
	Alloc
>::data_end()
{
	return data_end_;
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::const_pointer
majutsu::raw::detail::store<
	T,
	Alloc
>::data_end() const
{
	return data_end_;
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::iterator
majutsu::raw::detail::store<
	T,
	Alloc
>::begin()
{
	return
		this->data();
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::const_iterator
majutsu::raw::detail::store<
	T,
	Alloc
>::begin() const
{
	return
		this->data();
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::iterator
majutsu::raw::detail::store<
	T,
	Alloc
>::end()
{
	return
		this->data_end();
}

template<
	typename T,
	typename Alloc
>
typename
majutsu::raw::detail::store<
	T,
	Alloc
>::const_iterator
majutsu::raw::detail::store<
	T,
	Alloc
>::end() const
{
	return
		this->data_end();
}

template<
	typename T,
	typename Alloc
>
void
majutsu::raw::detail::store<
	T,
	Alloc
>::make_space(
	iterator const _first,
	size_type const _sz
)
{
	size_type const nsz(
		this->size() + _sz
	);

	if(
		nsz > this->capacity()
	)
	{
		size_type const new_cap(
			std::max(
				nsz,
				this->capacity() * 2
			)
		);

		pointer const new_data(
			alloc_.allocate(
				new_cap
			)
		);

		std::copy(
			data_,
			_first,
			new_data
		);

		std::copy(
			_first,
			data_end_,
			new_data + (_first - this->begin()) + _sz
		);

		this->deallocate();

		data_ = new_data;

		data_end_ = data_ + nsz;

		cap_ = data_ + new_cap;
	}
	else
	{
		std::copy_backward(
			_first,
			this->end(),
			this->data_end() + _sz
		);

		data_end_ += _sz;
	}
}

template<
	typename T,
	typename Alloc
>
void
majutsu::raw::detail::store<
	T,
	Alloc
>::erase(
	iterator const _first,
	iterator const _last
)
{
	std::copy(
		_last,
		this->end(),
		_first
	);

	data_end_ -=
		std::distance(
			_first,
			_last
		);
}

template<
	typename T,
	typename Alloc
>
void
majutsu::raw::detail::store<
	T,
	Alloc
>::deallocate()
{
	if(
		data_
	)
		alloc_.deallocate(
			data_,
			this->capacity()
		);
}

#endif
