/*
 * CommonJsonMessage.h
 *
 *  Created on: Feb 9, 2020
 *      Author: yanhualiu
 */

#ifndef SRC_MESSAGE_COMMONJSON_COMMONJSONMESSAGE_H_
#define SRC_MESSAGE_COMMONJSON_COMMONJSONMESSAGE_H_
#include <interface/message.h>
#include <json/json.h>
namespace lib {
namespace message {
namespace commonjson {

class CommonJsonMessage: public interface::IMessage, public Json::Value {
public: //IMessage
	virtual bool ToString(std::string &output) override {
		Json::StreamWriterBuilder builder;
		builder["indentation"] = "";
		output = Json::writeString(builder, *this);
		return true;
	}
	virtual bool FromString(const std::string &input) override {
		Json::CharReaderBuilder builder;
		Json::CharReader *reader = builder.newCharReader();
		std::string errors;

		bool parsingSuccessful = reader->parse(input.c_str(),
				input.c_str() + input.size(), this, &errors);
		delete reader;
		return parsingSuccessful;
	}
	virtual int GetMessageID(){
		return 0;
	}
	virtual const std::string GetMessageName() {
		return "CommonJson";
	}
};

} /* namespace commonjson */
} /* namespace message */
} /* namespace lib */

#endif /* SRC_MESSAGE_COMMONJSON_COMMONJSONMESSAGE_H_ */
