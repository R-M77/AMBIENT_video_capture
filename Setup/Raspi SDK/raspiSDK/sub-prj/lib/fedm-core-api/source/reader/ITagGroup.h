/**
*
* Copyright (C) FEIG ELECTRONIC GmbH. All rights reserved. Do not disclose.
*
* This software is the confidential and proprietary information of
* FEIG ELECTRONIC GmbH ("Confidential Information"). You shall not
* disclose such Confidential Information and shall use it only in
* accordance with the terms of the license agreement you entered
* into with FEIG ELECTRONIC GmbH.
*/

#if !defined(_FEDM_CORE_ISCAN_READER_MODULE_ITAG_COMMUNICATION_GROUP_H_INCLUDED_)
#define _FEDM_CORE_ISCAN_READER_MODULE_ITAG_COMMUNICATION_GROUP_H_INCLUDED_

#ifdef _FEDM_TAG_HANDLER

#include <map>
#include <string>
#include "../source/FEDM.h"
#include "../tag_handler/TH_Base.h"

class FEDM_ISCReaderModule;


namespace FEDM
{
	namespace Core
	{
		/// @brief Internal class providing Transponder specific Reader commands, when the Reader is working in Host Mode
		///
		/// <b>Description</b><br>
		/// This class realizes the nested interface with transponder specific methods like Inventory and Select for the Reader class ReaderModule.<br>
		/// The communication with Transponders is realized with TagHandler classes, which will be served with methods of this class.<br>
		/// Methods of this class can be called with the [ITag](@ref FEDM::Core::ReaderModule::ITag) member of ReaderModule.<br>
		/// <br>
		/// The concept of %TagHandler classes provides an efficient programming interface with different transponder types.
		/// It is based on the automatic identification of the type of the transponder after a successful inventory. With ISO 15693 compliant transponders 
		/// the manufacturer ID and the chipID, which are part of the serial number, are evaluated. With ISO 14443 compliant transponders the type of the 
		/// %TagHandler can be determined after a mandatory Select command based on the returned Card-Info or, in case of the explicit selection of a transponder driver 
		/// with the Select comand, the transponder driver selects the type of the %TagHandler.<br>
		/// All %TagHandler classes are derived from the base class TagHandler::TH_Base. Furthermore, the relationship between the different transponder types 
		/// is maped to derivations between %TagHandler classes.<br>
		/// %TagHandler classes are created, managed and deleted internally. After each call of Inventory(), the Reader class checks the present state of each %TagHandler 
		/// and removes the handler if the dedicated transponder is out of field. Thus, the life cycle of a %TagHandler is normally one inventory cycle.
		class _FEDM_ISC_CORE_EXT_CLASS ITagGroup
		{
			// friend classes have access rights to protected and private members
			friend class ReaderModule;
			friend class TagHandler::TH_Base;

		public:
			/// @brief Definition of a map type with detected TagHandlers after ITagGroup::Inventory
			///
			/// @param std::string IID of the Transponder
			/// @param FEDM::Core::TagHandler::TH_Base* Pointer to the TagHandler object, casted to base class
			typedef std::map<std::string, FEDM::Core::TagHandler::TH_Base*>					TH_LIST;
				
			/// Definition of an iterator for map type with detected Taghandlers after ITagGroup::Inventory
			typedef std::map<std::string, FEDM::Core::TagHandler::TH_Base*>::const_iterator	TH_LIST_ITOR;

		public:
				
			/// @brief Method executes synchronous Inventory command (for all IDENTIFICATION Readers)
			///
			/// @param[in] bAll when true (preset), Inventory is repeated as long as the Reader respond MORE status
			/// @param[in] ucMode MODE byte (Preset with 0) to adjust the Inventory. See Reader&apos;s System Manual for additional information.
			/// @param[in] ucAntennas Antenna Flag field to select specific antenna(s). Only available for Readers with internal Multiplexer.
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Call of an Inventory and collecting all found tags in a TagList of type %TagHandler base class [TH_Base](@ref FEDM::Core::TagHandler::TH_Base).<br>
			/// If successful, the list can be called with [GetTagList](@ref FEDM::Core::ITagGroup::GetTagList)<br>
			/// If applicable, the returned Transponder information is analyzed and the dedicated %TagHandler class is created. In all other cases, the %TagHandler base class is created.
			///
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// The following example demonstrates the principle work with Inventory, how to identify the returned %TagHandler types and how to work with the Transponder objects.<br>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// ITagGroup::TH_LIST* pTagList = NULL;
			/// ITagGroup::TH_LIST_ITOR itor;
			/// TagHandler::TH_Base* pTH = NULL;
			///
			///	int ret = reader.ITag.Inventory();
			/// if(ret)
			/// {
			///		if(ret < 0)
			///		{
			///			// we have an internal error
			///			cout << reader.GetErrorText(ret);
			///		}
			///		else
			///		{
			///			// we have a feedback from the Reader, signaling a problem
			///			cout << reader.GetStatusText(ret);
			///		}
			/// }
			/// else
			/// {
			///		const ITagGroup::TH_LIST& TagList = reader.ITag.GetTagList();
			///
			///		// iteration loop over all detected Transponders
			///		for( itor = TagList.begin(); itor != pTagList.end(); itor++ )
			///		{
			///			pTH = itor->second;
			///
			///			// is selected Transponder of standard ISO 14443-4?
			///			if(dynamic_cast<TagHandler::TH_ISO14443_4*>(pTH) != NULL)
			///			{
			///				TagHandler::TH_ISO14443_4* pTH_14443_4 = (TagHandler::TH_ISO14443_4*)pTH;
			///				
			///				// use of casted TagHandler
			///				cout << pTH_14443_4->GetManufacturerName();
			///			}
			///			// is selected Transponder of standard ISO 15693?
			///			else if(dynamic_cast<TagHandler::TH_ISO15693*>(pTH) != NULL)
			///			{
			///				TagHandler::TH_ISO15693* pTH_15693 = (TagHandler::TH_ISO15693*)pTH;
			///				
			///				// use of casted TagHandler
			///				cout << pTH_15693->GetManufacturerName();
			///			}
			///		}
			///	}
			///
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			int Inventory( bool bAll=true, unsigned char ucMode=0x00, unsigned char ucAntennas=1 );

			/// @brief Return of the Transponder list previous built with Inventory
			///
			/// @return List with all previously detected Transponder objects (TagHandler classes) or an empty list
			///
			/// <b>Description</b><br>
			const TH_LIST& GetTagList() { return m_mapTagHandler; }

			/// @brief Method for executing a synchronous Select command (for all IDENTIFICATION Readers, if supported by the applied standard)
			///
			/// @param[in] pTagHandler Pointer to TagHandler object from last Inventory()
			/// @param[in] uiTagDriver For manual selection of one special Transponder driver to be applied to in the Reader (only for some IDENTIFICATION Readers)
			/// @return
			/// -   0 if OK
			/// - < 0 [error code](@ref FEDM::Core::ErrorCode)
			/// - > 0 status byte of the responded protocol, if the Reader signals a problem. See Reader&apos;s System Manual for the full list with all status bytes.
			///
			/// <b>Description</b><br>
			/// Call of a Select command. For ISO 14443 Transponders, if applicable, the TagHandler class successive called with [GetSelectedTagHandler](@ref FEDM::Core::ITagGroup::GetSelectedTagHandler) is modified.
			/// Another Transponder, which is in the selected state will be switched to the idle state and the specified Transponder (in pTagHandler) is switched to the selected state.
			///
			/// @note See the following example how to identify the returned %TagHandler type and how to work with the Transponder object.<br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// TagHandler::TH_Base* pTH = NULL;
			///
			///	pTH = reader.ITag.GetTagHandler("0123456789ABCDEF");
			///	int ret = reader.ITag.Select(pTH);
			///	if(ret < 0)
			///	{
			///		// we have an internal error
			///		cout << reader.GetErrorText(ret);
			///	}
			///	else if(ret > 0)
			///	{
			///		// we have a feedback from the Reader, signaling a problem
			///		cout << reader.GetStatusText(ret);
			///	}
			///	else
			///	{
			///		pTH = GetSelectedTagHandler();
			///
			///		// inherited type of pTH can now be modified !!
			///
			///		// is selected Transponder of standard ISO 14443-4?
			///		if(dynamic_cast<TagHandler::TH_ISO14443_4*>(pTH) != NULL)
			///		{
			///			TagHandler::TH_ISO14443_4* pTH_14443_4 = (TagHandler::TH_ISO14443_4*)pTH;
			///			
			///			// use of casted TagHandler
			///			cout << pTH_14443_4->GetManufacturerName();
			///		}
			/// }
			///
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			int Select( TagHandler::TH_Base* pTagHandler, unsigned int uiTagDriver=0 );

			/// @brief Return the Transponder object, which is in the selected state
			///
			/// @return Pointer to TagHandler object, which represents a Transponder in selected state (down-casted to base %TagHandler class)<br>
			///  or NULL, if no tag is in selected state
			///
			/// <b>Description</b><br>
			/// This method returns the TagHandler, which is in the selected state.
			/// The Transponder in the field must be previously selected with the call of [Select](@ref FEDM::Core::ITagGroup::Select)
			TagHandler::TH_Base* GetSelectedTagHandler();
				
			/// @brief Return the Transponder object from the Transponder list, identified by the Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder
			///
			/// @param[in] sIDD Identifier Data (IDD), resp. UID, resp. EPC, resp. SNR of Transponder
			/// @return Pointer to a TagHandler object of actual Tag List (down-casted to base %TagHandler class)<br>
			///  or NULL, if IDD could not be found in the Tag List
			TagHandler::TH_Base* GetTagHandler(std::string sIDD);
				
			/// @brief Create a Transponder object for working in non-addressed mode
			///
			/// @param[in] uiTagHandlerType Specifies the TagHandler class, for which a %TagHandler object for non-addressed communication should be created to
			/// @return Pointer to new created %TagHandler object (down-casted to base %TagHandler class)<br>
			///  or NULL<br>
			///	-	if %TagHandler type does not support non-addressed communication
			///	-	if %TagHandler type could not be identified
			///
			/// <b>Description</b><br>
			/// A list of all %TagHandler type constants can be found in TagHandler::TH_Base
			///
			/// @note See the following example how to identify the returned %TagHandler type and how to work with the Transponder object.<br>
			/// <br>
			/// <remarks>
			/// <example>
			/// <br><b>Example:</b>
			/// <code>
			/// 
			/// using namespace FEDM::Core;
			/// 
			/// TagHandler::TH_Base* pTH = NULL;
			///
			///	pTH = reader.ITag.CreateNonAddressedTagHandler(TagHandler::TH_Base::TYPE_ISO15693);
			///	if(pTH == NULL)
			///	{
			///		// we have an internal error
			///		cout << reader.GetErrorText(ret);
			///	}
			///	else
			/// {
			///		// is Transponder of standard ISO 15693?
			///		if(dynamic_cast<TagHandler::TH_ISO15693*>(pTH) != NULL)
			///		{
			///			TagHandler::TH_ISO15693* pTH_15693 = (TagHandler::TH_ISO15693*)pTH;
			///			
			///			// use of casted TagHandler
			///			cout << pTH_15693->GetManufacturerName();
			///		}
			/// }
			///
			/// NOTE: reader is an object of type FEDM::Core::ReaderModule
			/// </code>
			/// </example>
			/// </remarks>
			TagHandler::TH_Base* CreateNonAddressedTagHandler(unsigned int uiTagHandlerType);

		private:
			ITagGroup();
			virtual ~ITagGroup();

			void ClearTagHandlerMap();
			int  AddNewTagHandler(FedmIscTagHandler* th);
			TagHandler::TH_Base* CreateTagHandler(FedmIscTagHandler* th);

			ReaderModule*			m_pParent;
			FEDM_ISCReaderModule*	m_pReader;
			TH_LIST	m_mapTagHandler;

			// Definition of an iterator for map type with detected Taghandlers after ITagGroup::Inventory
			typedef std::map<std::string, FEDM::Core::TagHandler::TH_Base*>::iterator TH_LIST_ITOR_P;
		};
	}
}

#endif // #ifdef _FEDM_TAG_HANDLER

#endif // !defined(_FEDM_CORE_ISCAN_READER_MODULE_ITAG_COMMUNICATION_GROUP_H_INCLUDED_)
