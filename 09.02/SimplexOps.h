#pragma once
#include <functional>
#include <math.h>
namespace OptLib
{
	namespace SimplexOps
	{																					//a+b=b+a
		namespace UnaryOps
		{
			template<class Scalar>
			struct plus
			{
				constexpr
					plus(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs + scalar;
				}
			protected:
				Scalar scalar;
			};
			
			template<class Scalar>
			struct minus
			{
				constexpr
					minus(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs - scalar;
				}
			protected:
				Scalar scalar;
			};

			template<class Scalar>
			struct mult
			{
				constexpr
					mult(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs * scalar;
				}
			protected:
				Scalar scalar;
			};

			template<class Scalar>
			struct del
			{
				constexpr
					del(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return ihs / scalar;
				}
			protected:
				Scalar scalar;
			};
			template<class Scalar>
			struct del1
			{
				/*constexpr*/
					del1(Scalar value) :scalar{ value } {};
				template< class T = void>
				T operator ()(const T& ihs)
				{

					return  scalar/ihs;
				}
			protected:
				Scalar scalar;
			};

			template< class T =void >
			struct Abs
			{
				/*constexpr*/
					
				T operator()(const T& ihs)
				{
					return abs(ihs);
				}
			};


			template< class T =void>
			struct Sqrt
			{
				/*constexpr*/

					T operator()(const T& ihs)
				{
					return sqrt(ihs);
				}
			};

		}
		namespace BinaryOps
		{
			template <class T = void>
			using plus = std::plus<T>;

			template <class T=void>
			struct del
			{
				/*constexpr*/
				T operator ()(const T& rhs, const T& ihs)
				{

					return rhs / ihs;
				}
			};

		}
	}
}

/*
template <class T = void>
Point<dim> operator +(const PointVal<dim>&p1,const PointVal<dim>&p2)
{
return PointVal<dim>{p1.p+p2.p,p1.val+p2.val};
};
+double val не добавляется
-
-double аналогично
p/double и точка и val
*double и точка и val
sqrt
abs

*/