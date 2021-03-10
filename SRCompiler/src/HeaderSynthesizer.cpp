#include "HeaderSynthesizer.h"

HeaderSynthesizer::HeaderSynthesizer(TokenStore* _token_store)
{
	tokenStore = _token_store;
}

void HeaderSynthesizer::synthResource()
{
	//BEBEKSI
	std::string actorTemplate = "<Actor #actorName>\n\t<var>\n\t\t#var\n\t</var>\n\t<components>\n\t\t#component\n\t</components>\n</Actor>\n";
	std::ofstream outputFile;
	outputFile.open("Resources.txt");
	

	for (int i = 0; i < tokenStore->actorTokenList.size(); i++)
	{
		std::string actorTemplateBuffer = actorTemplate;
		int index = actorTemplateBuffer.find("#actorName", 0);

		actorTemplateBuffer.replace(index, 10, tokenStore->actorTokenList.at(i)->actorName);

		index = actorTemplateBuffer.find("#var", 0);
		actorTemplateBuffer.replace(index, 4, tokenStore->actorTokenList.at(i)->variables);

		index = actorTemplateBuffer.find("#component", 0);

		actorTemplateBuffer.replace(index, 10, tokenStore->actorTokenList.at(i)->components);
		outputFile << actorTemplateBuffer;
	}

	std::string componentTemplate = "<Component #componentName>\n\t<var>\n\t\t#var\n\t</var>\n</Component>\n";

	for (int i = 0; i < tokenStore->componentTokenList.size(); i++)
	{
		std::string componentTemplateBuffer = componentTemplate;
		int index = componentTemplateBuffer.find("#componentName", 0);
		
		componentTemplateBuffer.replace(index, 14, tokenStore->componentTokenList.at(i)->componentName);

		index = componentTemplateBuffer.find("#var", 0);
		componentTemplateBuffer.replace(index, 4, tokenStore->componentTokenList.at(i)->variables);
		outputFile << componentTemplateBuffer;
	}

	



	
	
}

