#ifndef JSON_READER_HPP_INCLUDED
#define JSON_READER_HPP_INCLUDED

#include <string>

#include <boost/noncopyable.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


/**
 *	@class
 *		JSONReader
 *
 *	@brief
 *		A class for reading JSON files
 *
 *	@details
 *		A convenience class to encapsulate a property tree (preventing a "dead tree" from ever being created)
 *		"Dead Tree" - A property tree that has not yet been fed a file.
 *
 *	@see
 *		boost::property_tree
 *		boost::noncopyable
 */
class JSONReader : private boost::noncopyable
{

	///The underlying ptree
	boost::property_tree::ptree tree_;

	public:
	
		/// Constructs a JSONReader
		/**
		 *	@pre
		 *		The specified file must exist
		 *	@post
		 *		This JSONReader now contains the parsed file
		 *	@throw
		 *		This constructor may throw boost::property_tree::ptree_error if a parsing error occurs
		 *	@note
		 *		This constructor makes the strong exception guarantee
		 */
		JSONReader(const std::string& fileName)
		{
			boost::property_tree::read_json(fileName, tree_);
		}

		/// Attempts to read the value of the provided key
		/**
		 *	@pre
		 *		The specified key must exist
		 *	@post
		 *		None
		 *	@param key
		 *		The key to read
		 *	@return
		 *		The value read from the provided key
		 *	@throw
		 *		This method may throw boost::property_tree::ptree_error if the data cannot be converted to the template type
		 *		or if the provided key does not exist
		 *	@note
		 *		This method makes the strong exception guarantee
		 */
		template<typename T>
		T read(const std::string& key)
		{
			return this->tree_.get<T>(key);
		}

		/// Destroys an JSONReader
		/**
		 *	@pre
		 *		None
		 *	@post
		 *		None
		 *	@note
		 *		This destructor makes the no-throw guarantee
		 */
		~JSONReader(void)
		{
		
		}


};
#endif