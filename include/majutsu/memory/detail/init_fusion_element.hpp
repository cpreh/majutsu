//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MAJUTSU_MEMORY_DETAIL_INIT_FUSION_ELEMENT_HPP_INCLUDED
#define MAJUTSU_MEMORY_DETAIL_INIT_FUSION_ELEMENT_HPP_INCLUDED

#include <majutsu/is_constant.hpp>
#include <majutsu/is_role.hpp>
#include <majutsu/unwrap_role.hpp>
#include <majutsu/detail/tag_is_same.hpp>
#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/fusion/algorithm/query/find_if.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace majutsu
{
namespace memory
{
namespace detail
{

template<
	typename Elements,
	typename Arguments
>
class init_fusion_element
{
	FCPPT_NONASSIGNABLE(
		init_fusion_element
	);
public:
	template<
		typename
	>
	struct result;

	template<
		typename Elem
	>
	struct result<
		init_fusion_element(
			Elem
		)
	>
	{
		typedef typename std::remove_const<
			typename std::remove_reference<
				Elem
			>::type
		>::type::type type;
	};

	explicit
	init_fusion_element(
		Arguments &_arguments
	)
	:
		arguments_(
			_arguments
		)
	{
	}

	template<
		typename Type
	>
	typename boost::enable_if<
		majutsu::is_constant<
			Type
		>,
		typename Type::type
	>::type
	operator()(
		Type const &
	) const
	{
		return
			Type::value;
	}

	template<
		typename Role
	>
	typename boost::enable_if<
		majutsu::is_role<
			Role
		>,
		typename Role::type
	>::type
	operator()(
		Role const &
	) const
	{
		return
			boost::fusion::deref(
				boost::fusion::find_if<
					majutsu::detail::tag_is_same<
						typename
						majutsu::unwrap_role<
							Role
						>::type,
						boost::mpl::_1
					>
				>(
					arguments_
				)
			).value();
	}

	template<
		typename Type
	>
	typename boost::disable_if<
		boost::mpl::or_<
			majutsu::is_constant<
				Type
			>,
			majutsu::is_role<
				Type
			>
		>,
		typename Type::type
	>::type
	operator()(
		Type const &
	) const
	{
		// TODO: Error?
		return
			typename Type::type();
	}
private:
	Arguments &arguments_;
};

}
}
}

#endif
