#pragma once

#ifndef __H_DESCRIPTORS__
#define __H_DESCRIPTORS__

#include <XFSHeaders.h>

#include <string>

#define DESCRIBE_XFS_INFO(code)					__N_DESCRIPTOR__::get_xfs_info(code).c_str()
#define DESCRIBE_XFS_EXECUTE(code)				__N_DESCRIPTOR__::get_xfs_execute(code).c_str()
#define DESCRIBE_XFS_ERROR(code)				__N_DESCRIPTOR__::get_xfs_error(code).c_str()
#define DESCRIBE_XFS_MESSAGE(code)				__N_DESCRIPTOR__::get_xfs_message(code).c_str()

namespace __N_DESCRIPTOR__
{
	/*=================================================================*/														
	/* XFS Device Class */																										
	/*=================================================================*/														
																																
	static std::string get_xfs_device_class(DWORD macro)																		
	{																															
		std::string _str{};																										
		switch (macro)																											
		{																														
		case WFS_SERVICE_CLASS_PTR							: _str.assign("WFS_SERVICE_CLASS_PTR");								break;
		case WFS_SERVICE_CLASS_IDC							: _str.assign("WFS_SERVICE_CLASS_IDC");								break;
		case WFS_SERVICE_CLASS_CDM							: _str.assign("WFS_SERVICE_CLASS_CDM");								break;
		case WFS_SERVICE_CLASS_PIN							: _str.assign("WFS_SERVICE_CLASS_PIN");								break;
		case WFS_SERVICE_CLASS_CHK							: _str.assign("WFS_SERVICE_CLASS_CHK");								break;
		case WFS_SERVICE_CLASS_DEP							: _str.assign("WFS_SERVICE_CLASS_DEP");								break;
		case WFS_SERVICE_CLASS_TTU							: _str.assign("WFS_SERVICE_CLASS_TTU");								break;
		case WFS_SERVICE_CLASS_SIU							: _str.assign("WFS_SERVICE_CLASS_SIU");								break;
		case WFS_SERVICE_CLASS_VDM							: _str.assign("WFS_SERVICE_CLASS_VDM");								break;
		case WFS_SERVICE_CLASS_CAM							: _str.assign("WFS_SERVICE_CLASS_CAM");								break;
		case WFS_SERVICE_CLASS_ALM							: _str.assign("WFS_SERVICE_CLASS_ALM");								break;
		case WFS_SERVICE_CLASS_CEU							: _str.assign("WFS_SERVICE_CLASS_CEU");								break;
		case WFS_SERVICE_CLASS_CIM							: _str.assign("WFS_SERVICE_CLASS_CIM");								break;
		case WFS_SERVICE_CLASS_BCR							: _str.assign("WFS_SERVICE_CLASS_BCR");								break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS Info Commands */																										
	/*=================================================================*/														
																																
	static std::string get_xfs_info(DWORD macro) noexcept																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		// PTR																													
		case WFS_INF_PTR_STATUS								: _str.assign("WFS_INF_PTR_STATUS");								break;
		case WFS_INF_PTR_CAPABILITIES						: _str.assign("WFS_INF_PTR_CAPABILITIES");							break;
		case WFS_INF_PTR_FORM_LIST							: _str.assign("WFS_INF_PTR_FORM_LIST");								break;
		case WFS_INF_PTR_MEDIA_LIST							: _str.assign("WFS_INF_PTR_MEDIA_LIST");							break;
		case WFS_INF_PTR_QUERY_FORM							: _str.assign("WFS_INF_PTR_QUERY_FORM");							break;
		case WFS_INF_PTR_QUERY_MEDIA						: _str.assign("WFS_INF_PTR_QUERY_MEDIA");							break;
		case WFS_INF_PTR_QUERY_FIELD						: _str.assign("WFS_INF_PTR_QUERY_FIELD");							break;
																																
		// IDC																													
		case WFS_INF_IDC_STATUS								: _str.assign("WFS_INF_IDC_STATUS");								break;
		case WFS_INF_IDC_CAPABILITIES						: _str.assign("WFS_INF_IDC_CAPABILITIES");							break;
		case WFS_INF_IDC_FORM_LIST							: _str.assign("WFS_INF_IDC_FORM_LIST");								break;
		case WFS_INF_IDC_QUERY_FORM							: _str.assign("WFS_INF_IDC_QUERY_FORM");							break;
																																
		// CDM																													
		case WFS_INF_CDM_STATUS								: _str.assign("WFS_INF_CDM_STATUS");								break;
		case WFS_INF_CDM_CAPABILITIES						: _str.assign("WFS_INF_CDM_CAPABILITIES");							break;
		case WFS_INF_CDM_CASH_UNIT_INFO						: _str.assign("WFS_INF_CDM_CASH_UNIT_INFO");						break;
		case WFS_INF_CDM_TELLER_INFO						: _str.assign("WFS_INF_CDM_TELLER_INFO");							break;
		case WFS_INF_CDM_CURRENCY_EXP						: _str.assign("WFS_INF_CDM_CURRENCY_EXP");							break;
		case WFS_INF_CDM_MIX_TYPES							: _str.assign("WFS_INF_CDM_MIX_TYPES");								break;
		case WFS_INF_CDM_MIX_TABLE							: _str.assign("WFS_INF_CDM_MIX_TABLE");								break;
		case WFS_INF_CDM_PRESENT_STATUS						: _str.assign("WFS_INF_CDM_PRESENT_STATUS");						break;
																																
		// PIN																													
		case WFS_INF_PIN_STATUS								: _str.assign("WFS_INF_PIN_STATUS");								break;
		case WFS_INF_PIN_CAPABILITIES						: _str.assign("WFS_INF_PIN_CAPABILITIES");							break;
		case WFS_INF_PIN_KEY_DETAIL							: _str.assign("WFS_INF_PIN_KEY_DETAIL");							break;
		case WFS_INF_PIN_FUNCKEY_DETAIL						: _str.assign("WFS_INF_PIN_FUNCKEY_DETAIL");						break;
		case WFS_INF_PIN_HSM_TDATA							: _str.assign("WFS_INF_PIN_HSM_TDATA");								break;
		case WFS_INF_PIN_KEY_DETAIL_EX						: _str.assign("WFS_INF_PIN_KEY_DETAIL_EX");							break;
																																
		// CHK																													
		case WFS_INF_CHK_STATUS								: _str.assign("WFS_INF_CHK_STATUS");								break;
		case WFS_INF_CHK_CAPABILITIES						: _str.assign("WFS_INF_CHK_CAPABILITIES");							break;
		case WFS_INF_CHK_FORM_LIST							: _str.assign("WFS_INF_CHK_FORM_LIST");								break;
		case WFS_INF_CHK_MEDIA_LIST							: _str.assign("WFS_INF_CHK_MEDIA_LIST");							break;
		case WFS_INF_CHK_QUERY_FORM							: _str.assign("WFS_INF_CHK_QUERY_FORM");							break;
		case WFS_INF_CHK_QUERY_MEDIA						: _str.assign("WFS_INF_CHK_QUERY_MEDIA");							break;
		case WFS_INF_CHK_QUERY_FIELD						: _str.assign("WFS_INF_CHK_QUERY_FIELD");							break;
																																
		// DEP																													
		case WFS_INF_DEP_STATUS								: _str.assign("WFS_INF_DEP_STATUS");								break;
		case WFS_INF_DEP_CAPABILITIES						: _str.assign("WFS_INF_DEP_CAPABILITIES");							break;
																																
		// TTU																													
		case WFS_INF_TTU_STATUS								: _str.assign("WFS_INF_TTU_STATUS");								break;
		case WFS_INF_TTU_CAPABILITIES						: _str.assign("WFS_INF_TTU_CAPABILITIES");							break;
		case WFS_INF_TTU_FORM_LIST							: _str.assign("WFS_INF_TTU_FORM_LIST");								break;
		case WFS_INF_TTU_QUERY_FORM							: _str.assign("WFS_INF_TTU_QUERY_FORM");							break;
		case WFS_INF_TTU_QUERY_FIELD						: _str.assign("WFS_INF_TTU_QUERY_FIELD");							break;
		case WFS_INF_TTU_KEY_DETAIL							: _str.assign("WFS_INF_TTU_KEY_DETAIL");							break;
																																
		// SIU																													
		case WFS_INF_SIU_STATUS								: _str.assign("WFS_INF_SIU_STATUS");								break;
		case WFS_INF_SIU_CAPABILITIES						: _str.assign("WFS_INF_SIU_CAPABILITIES");							break;
																																
		// VDM																													
		case WFS_INF_VDM_STATUS								: _str.assign("WFS_INF_VDM_STATUS");								break;
		case WFS_INF_VDM_CAPABILITIES						: _str.assign("WFS_INF_VDM_CAPABILITIES");							break;
																																
		// CAM																													
		case WFS_INF_CAM_STATUS								: _str.assign("WFS_INF_CAM_STATUS");								break;
		case WFS_INF_CAM_CAPABILITIES						: _str.assign("WFS_INF_CAM_CAPABILITIES");							break;
																																
		// CIM																													
		case WFS_INF_CIM_STATUS								: _str.assign("WFS_INF_CIM_STATUS");								break;
		case WFS_INF_CIM_CAPABILITIES						: _str.assign("WFS_INF_CIM_CAPABILITIES");							break;
		case WFS_INF_CIM_CASH_UNIT_INFO						: _str.assign("WFS_INF_CIM_CASH_UNIT_INFO");						break;
		case WFS_INF_CIM_TELLER_INFO						: _str.assign("WFS_INF_CIM_TELLER_INFO");							break;
		case WFS_INF_CIM_CURRENCY_EXP						: _str.assign("WFS_INF_CIM_CURRENCY_EXP");							break;
		case WFS_INF_CIM_BANKNOTE_TYPES						: _str.assign("WFS_INF_CIM_BANKNOTE_TYPES");						break;
		case WFS_INF_CIM_CASH_IN_STATUS						: _str.assign("WFS_INF_CIM_CASH_IN_STATUS");						break;
		case WFS_INF_CIM_GET_P6_INFO						: _str.assign("WFS_INF_CIM_GET_P6_INFO");							break;
		case WFS_INF_CIM_GET_P6_SIGNATURE					: _str.assign("WFS_INF_CIM_GET_P6_SIGNATURE");						break;
																																
		default												: _str.assign("Unknown INFO Command");								break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS Execute Commands */																									
	/*=================================================================*/														
																																
	static std::string get_xfs_execute(DWORD macro) noexcept																	
	{																															
		std::string _str;																										
																																
		switch (macro)																											
		{																														
		// PTR																													
		case WFS_CMD_PTR_CONTROL_MEDIA						: _str.assign("WFS_CMD_PTR_CONTROL_MEDIA");							break;
		case WFS_CMD_PTR_PRINT_FORM							: _str.assign("WFS_CMD_PTR_PRINT_FORM");							break;
		case WFS_CMD_PTR_READ_FORM							: _str.assign("WFS_CMD_PTR_READ_FORM");								break;
		case WFS_CMD_PTR_RAW_DATA							: _str.assign("WFS_CMD_PTR_RAW_DATA");								break;
		case WFS_CMD_PTR_MEDIA_EXTENTS						: _str.assign("WFS_CMD_PTR_MEDIA_EXTENTS");							break;
		case WFS_CMD_PTR_RESET_COUNT						: _str.assign("WFS_CMD_PTR_RESET_COUNT");							break;
		case WFS_CMD_PTR_READ_IMAGE							: _str.assign("WFS_CMD_PTR_READ_IMAGE");							break;
		case WFS_CMD_PTR_RESET								: _str.assign("WFS_CMD_PTR_RESET");									break;
		case WFS_CMD_PTR_RETRACT_MEDIA						: _str.assign("WFS_CMD_PTR_RETRACT_MEDIA");							break;
		case WFS_CMD_PTR_DISPENSE_PAPER						: _str.assign("WFS_CMD_PTR_DISPENSE_PAPER");						break;
																																
		// IDC																													
		case WFS_CMD_IDC_READ_TRACK							: _str.assign("WFS_CMD_IDC_READ_TRACK");							break;
		case WFS_CMD_IDC_WRITE_TRACK						: _str.assign("WFS_CMD_IDC_WRITE_TRACK");							break;
		case WFS_CMD_IDC_EJECT_CARD							: _str.assign("WFS_CMD_IDC_EJECT_CARD");							break;
		case WFS_CMD_IDC_RETAIN_CARD						: _str.assign("WFS_CMD_IDC_RETAIN_CARD");							break;
		case WFS_CMD_IDC_RESET_COUNT						: _str.assign("WFS_CMD_IDC_RESET_COUNT");							break;
		case WFS_CMD_IDC_SETKEY								: _str.assign("WFS_CMD_IDC_SETKEY");								break;
		case WFS_CMD_IDC_READ_RAW_DATA						: _str.assign("WFS_CMD_IDC_READ_RAW_DATA");							break;
		case WFS_CMD_IDC_WRITE_RAW_DATA						: _str.assign("WFS_CMD_IDC_WRITE_RAW_DATA");						break;
		case WFS_CMD_IDC_CHIP_IO							: _str.assign("WFS_CMD_IDC_CHIP_IO");								break;
		case WFS_CMD_IDC_RESET								: _str.assign("WFS_CMD_IDC_RESET");									break;
		case WFS_CMD_IDC_CHIP_POWER							: _str.assign("WFS_CMD_IDC_CHIP_POWER");							break;
		case WFS_CMD_IDC_PARSE_DATA							: _str.assign("WFS_CMD_IDC_PARSE_DATA");							break;
																																
		// CDM																													
		case WFS_CMD_CDM_DENOMINATE							: _str.assign("WFS_CMD_CDM_DENOMINATE");							break;
		case WFS_CMD_CDM_DISPENSE							: _str.assign("WFS_CMD_CDM_DISPENSE");								break;
		case WFS_CMD_CDM_PRESENT							: _str.assign("WFS_CMD_CDM_PRESENT");								break;
		case WFS_CMD_CDM_REJECT								: _str.assign("WFS_CMD_CDM_REJECT");								break;
		case WFS_CMD_CDM_RETRACT							: _str.assign("WFS_CMD_CDM_RETRACT");								break;
		case WFS_CMD_CDM_OPEN_SHUTTER						: _str.assign("WFS_CMD_CDM_OPEN_SHUTTER");							break;
		case WFS_CMD_CDM_CLOSE_SHUTTER						: _str.assign("WFS_CMD_CDM_CLOSE_SHUTTER");							break;
		case WFS_CMD_CDM_SET_TELLER_INFO					: _str.assign("WFS_CMD_CDM_SET_TELLER_INFO");						break;
		case WFS_CMD_CDM_SET_CASH_UNIT_INFO					: _str.assign("WFS_CMD_CDM_SET_CASH_UNIT_INFO");					break;
		case WFS_CMD_CDM_START_EXCHANGE						: _str.assign("WFS_CMD_CDM_START_EXCHANGE");						break;
		case WFS_CMD_CDM_END_EXCHANGE						: _str.assign("WFS_CMD_CDM_END_EXCHANGE");							break;
		case WFS_CMD_CDM_OPEN_SAFE_DOOR						: _str.assign("WFS_CMD_CDM_OPEN_SAFE_DOOR");						break;
		case WFS_CMD_CDM_CALIBRATE_CASH_UNIT				: _str.assign("WFS_CMD_CDM_CALIBRATE_CASH_UNIT");					break;
		case WFS_CMD_CDM_SET_MIX_TABLE						: _str.assign("WFS_CMD_CDM_SET_MIX_TABLE");							break;
		case WFS_CMD_CDM_RESET								: _str.assign("WFS_CMD_CDM_RESET");									break;
		case WFS_CMD_CDM_TEST_CASH_UNITS					: _str.assign("WFS_CMD_CDM_TEST_CASH_UNITS");						break;
		case WFS_CMD_CDM_COUNT								: _str.assign("WFS_CMD_CDM_COUNT");									break;
																																
		// PIN																													
		case WFS_CMD_PIN_CRYPT								: _str.assign("WFS_CMD_PIN_CRYPT");									break;
		case WFS_CMD_PIN_IMPORT_KEY							: _str.assign("WFS_CMD_PIN_IMPORT_KEY");							break;
		case WFS_CMD_PIN_GET_PIN							: _str.assign("WFS_CMD_PIN_GET_PIN");								break;
		case WFS_CMD_PIN_GET_PINBLOCK						: _str.assign("WFS_CMD_PIN_GET_PINBLOCK");							break;
		case WFS_CMD_PIN_GET_DATA							: _str.assign("WFS_CMD_PIN_GET_DATA");								break;
		case WFS_CMD_PIN_INITIALIZATION						: _str.assign("WFS_CMD_PIN_INITIALIZATION");						break;
		case WFS_CMD_PIN_LOCAL_DES							: _str.assign("WFS_CMD_PIN_LOCAL_DES");								break;
		case WFS_CMD_PIN_LOCAL_EUROCHEQUE					: _str.assign("WFS_CMD_PIN_LOCAL_EUROCHEQUE");						break;
		case WFS_CMD_PIN_LOCAL_VISA							: _str.assign("WFS_CMD_PIN_LOCAL_VISA");							break;
		case WFS_CMD_PIN_CREATE_OFFSET						: _str.assign("WFS_CMD_PIN_CREATE_OFFSET");							break;
		case WFS_CMD_PIN_DERIVE_KEY							: _str.assign("WFS_CMD_PIN_DERIVE_KEY");							break;
		case WFS_CMD_PIN_PRESENT_IDC						: _str.assign("WFS_CMD_PIN_PRESENT_IDC");							break;
		case WFS_CMD_PIN_LOCAL_BANKSYS						: _str.assign("WFS_CMD_PIN_LOCAL_BANKSYS");							break;
		case WFS_CMD_PIN_BANKSYS_IO							: _str.assign("WFS_CMD_PIN_BANKSYS_IO");							break;
		case WFS_CMD_PIN_RESET								: _str.assign("WFS_CMD_PIN_RESET");									break;
		case WFS_CMD_PIN_HSM_SET_TDATA						: _str.assign("WFS_CMD_PIN_HSM_SET_TDATA");							break;
		case WFS_CMD_PIN_SECURE_MSG_SEND					: _str.assign("WFS_CMD_PIN_SECURE_MSG_SEND");						break;
		case WFS_CMD_PIN_SECURE_MSG_RECEIVE					: _str.assign("WFS_CMD_PIN_SECURE_MSG_RECEIVE");					break;
		case WFS_CMD_PIN_GET_JOURNAL						: _str.assign("WFS_CMD_PIN_GET_JOURNAL");							break;
		case WFS_CMD_PIN_IMPORT_KEY_EX						: _str.assign("WFS_CMD_PIN_IMPORT_KEY_EX");							break;
		case WFS_CMD_PIN_ENC_IO								: _str.assign("WFS_CMD_PIN_ENC_IO");								break;
		case WFS_CMD_PIN_HSM_INIT							: _str.assign("WFS_CMD_PIN_HSM_INIT");								break;
		case WFS_CMD_PIN_IMPORT_RSA_PUBLIC_KEY				: _str.assign("WFS_CMD_PIN_IMPORT_RSA_PUBLIC_KEY");					break;
		case WFS_CMD_PIN_EXPORT_RSA_ISSUER_SIGNED_ITEM		: _str.assign("WFS_CMD_PIN_EXPORT_RSA_ISSUER_SIGNED_ITEM");			break;
		case WFS_CMD_PIN_IMPORT_RSA_SIGNED_DES_KEY			: _str.assign("WFS_CMD_PIN_IMPORT_RSA_SIGNED_DES_KEY");				break;
		case WFS_CMD_PIN_GENERATE_RSA_KEY_PAIR				: _str.assign("WFS_CMD_PIN_GENERATE_RSA_KEY_PAIR");					break;
		case WFS_CMD_PIN_EXPORT_RSA_EPP_SIGNED_ITEM			: _str.assign("WFS_CMD_PIN_EXPORT_RSA_EPP_SIGNED_ITEM");			break;
		case WFS_CMD_PIN_LOAD_CERTIFICATE					: _str.assign("WFS_CMD_PIN_LOAD_CERTIFICATE");						break;
		case WFS_CMD_PIN_GET_CERTIFICATE					: _str.assign("WFS_CMD_PIN_GET_CERTIFICATE");						break;
		case WFS_CMD_PIN_REPLACE_CERTIFICATE				: _str.assign("WFS_CMD_PIN_REPLACE_CERTIFICATE");					break;
		case WFS_CMD_PIN_START_KEY_EXCHANGE					: _str.assign("WFS_CMD_PIN_START_KEY_EXCHANGE");					break;
		case WFS_CMD_PIN_IMPORT_RSA_ENCIPHERED_PKCS7_KEY	: _str.assign("WFS_CMD_PIN_IMPORT_RSA_ENCIPHERED_PKCS7_KEY");		break;
		case WFS_CMD_PIN_EMV_IMPORT_PUBLIC_KEY				: _str.assign("WFS_CMD_PIN_EMV_IMPORT_PUBLIC_KEY");					break;
		case WFS_CMD_PIN_DIGEST								: _str.assign("WFS_CMD_PIN_DIGEST");								break;
																																
		// CHK																													
		case WFS_CMD_CHK_PROCESS_FORM						: _str.assign("WFS_CMD_CHK_PROCESS_FORM");							break;
		case WFS_CMD_CHK_RESET								: _str.assign("WFS_CMD_CHK_RESET");									break;
																																
		// DEP																													
		case WFS_CMD_DEP_ENTRY								: _str.assign("WFS_CMD_DEP_ENTRY");									break;
		case WFS_CMD_DEP_DISPENSE							: _str.assign("WFS_CMD_DEP_DISPENSE");								break;
		case WFS_CMD_DEP_RETRACT							: _str.assign("WFS_CMD_DEP_RETRACT");								break;
		case WFS_CMD_DEP_CLEAR_TRANSPORT					: _str.assign("WFS_CMD_DEP_CLEAR_TRANSPORT");						break;
		case WFS_CMD_DEP_RESET_COUNT						: _str.assign("WFS_CMD_DEP_RESET_COUNT");							break;
		case WFS_CMD_DEP_RESET								: _str.assign("WFS_CMD_DEP_RESET");									break;
																																
		// TTU																													
		case WFS_CMD_TTU_BEEP								: _str.assign("WFS_CMD_TTU_BEEP");									break;
		case WFS_CMD_TTU_CLEARSCREEN						: _str.assign("WFS_CMD_TTU_CLEARSCREEN");							break;
		case WFS_CMD_TTU_DISPLIGHT							: _str.assign("WFS_CMD_TTU_DISPLIGHT");								break;
		case WFS_CMD_TTU_SET_LED							: _str.assign("WFS_CMD_TTU_SET_LED");								break;
		case WFS_CMD_TTU_SET_RESOLUTION						: _str.assign("WFS_CMD_TTU_SET_RESOLUTION");						break;
		case WFS_CMD_TTU_WRITE_FORM							: _str.assign("WFS_CMD_TTU_WRITE_FORM");							break;
		case WFS_CMD_TTU_READ_FORM							: _str.assign("WFS_CMD_TTU_READ_FORM");								break;
		case WFS_CMD_TTU_WRITE								: _str.assign("WFS_CMD_TTU_WRITE");									break;
		case WFS_CMD_TTU_READ								: _str.assign("WFS_CMD_TTU_READ");									break;
		case WFS_CMD_TTU_RESET								: _str.assign("WFS_CMD_TTU_RESET");									break;
																																
		// SIU																													
		case WFS_CMD_SIU_ENABLE_EVENTS						: _str.assign("WFS_CMD_SIU_ENABLE_EVENTS");							break;
		case WFS_CMD_SIU_SET_PORTS							: _str.assign("WFS_CMD_SIU_SET_PORTS");								break;
		case WFS_CMD_SIU_SET_DOOR							: _str.assign("WFS_CMD_SIU_SET_DOOR");								break;
		case WFS_CMD_SIU_SET_INDICATOR						: _str.assign("WFS_CMD_SIU_SET_INDICATOR");							break;
		case WFS_CMD_SIU_SET_AUXILIARY						: _str.assign("WFS_CMD_SIU_SET_AUXILIARY");							break;
		case WFS_CMD_SIU_SET_GUIDLIGHT						: _str.assign("WFS_CMD_SIU_SET_GUIDLIGHT");							break;
		case WFS_CMD_SIU_RESET								: _str.assign("WFS_CMD_SIU_RESET");									break;
																																
		// VDM																													
		case WFS_CMD_VDM_ENTER_MODE_REQ						: _str.assign("WFS_CMD_VDM_ENTER_MODE_REQ");						break;
		case WFS_CMD_VDM_ENTER_MODE_ACK						: _str.assign("WFS_CMD_VDM_ENTER_MODE_ACK");						break;
		case WFS_CMD_VDM_EXIT_MODE_REQ						: _str.assign("WFS_CMD_VDM_EXIT_MODE_REQ");							break;
		case WFS_CMD_VDM_EXIT_MODE_ACK						: _str.assign("WFS_CMD_VDM_EXIT_MODE_ACK");							break;
																																
		// CAM																													
		case WFS_CMD_CAM_TAKE_PICTURE						: _str.assign("WFS_CMD_CAM_TAKE_PICTURE");							break;
		case WFS_CMD_CAM_RESET								: _str.assign("WFS_CMD_CAM_RESET");									break;
																																
		// CIM																													
		case WFS_CMD_CIM_CASH_IN_START						: _str.assign("WFS_CMD_CIM_CASH_IN_START");							break;
		case WFS_CMD_CIM_CASH_IN							: _str.assign("WFS_CMD_CIM_CASH_IN");								break;
		case WFS_CMD_CIM_CASH_IN_END						: _str.assign("WFS_CMD_CIM_CASH_IN_END");							break;
		case WFS_CMD_CIM_CASH_IN_ROLLBACK					: _str.assign("WFS_CMD_CIM_CASH_IN_ROLLBACK");						break;
		case WFS_CMD_CIM_RETRACT							: _str.assign("WFS_CMD_CIM_RETRACT");								break;
		case WFS_CMD_CIM_OPEN_SHUTTER						: _str.assign("WFS_CMD_CIM_OPEN_SHUTTER");							break;
		case WFS_CMD_CIM_CLOSE_SHUTTER						: _str.assign("WFS_CMD_CIM_CLOSE_SHUTTER");							break;
		case WFS_CMD_CIM_SET_TELLER_INFO					: _str.assign("WFS_CMD_CIM_SET_TELLER_INFO");						break;
		case WFS_CMD_CIM_SET_CASH_UNIT_INFO					: _str.assign("WFS_CMD_CIM_SET_CASH_UNIT_INFO");					break;
		case WFS_CMD_CIM_START_EXCHANGE						: _str.assign("WFS_CMD_CIM_START_EXCHANGE");						break;
		case WFS_CMD_CIM_END_EXCHANGE						: _str.assign("WFS_CMD_CIM_END_EXCHANGE");							break;
		case WFS_CMD_CIM_OPEN_SAFE_DOOR						: _str.assign("WFS_CMD_CIM_OPEN_SAFE_DOOR");						break;
		case WFS_CMD_CIM_RESET								: _str.assign("WFS_CMD_CIM_RESET");									break;
		case WFS_CMD_CIM_CONFIGURE_CASH_IN_UNITS			: _str.assign("WFS_CMD_CIM_CONFIGURE_CASH_IN_UNITS");				break;
		case WFS_CMD_CIM_CONFIGURE_NOTETYPES				: _str.assign("WFS_CMD_CIM_CONFIGURE_NOTETYPES");					break;
		case WFS_CMD_CIM_CREATE_P6_SIGNATURE				: _str.assign("WFS_CMD_CIM_CREATE_P6_SIGNATURE");					break;
		case WFS_CMD_CIM_AUDIT								: _str.assign("WFS_CMD_CIM_AUDIT");									break;
																																
		default												: _str.assign("Unknown EXECUTE Command");							break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS Error Codes */																										
	/*=================================================================*/														
																																
	static std::string get_xfs_error(DWORD macro) noexcept																		
	{																															
		std::string _str;																										
		switch ((int)macro)																										
		{																														
		// General 																												
		case WFS_SUCCESS									: _str.assign("WFS_SUCCESS");										break;
		case WFS_ERR_ALREADY_STARTED						: _str.assign("WFS_ERR_ALREADY_STARTED");							break;
		case WFS_ERR_API_VER_TOO_HIGH						: _str.assign("WFS_ERR_API_VER_TOO_HIGH");							break;
		case WFS_ERR_API_VER_TOO_LOW						: _str.assign("WFS_ERR_API_VER_TOO_LOW");							break;
		case WFS_ERR_CANCELED								: _str.assign("WFS_ERR_CANCELED");									break;
		case WFS_ERR_CFG_INVALID_HKEY						: _str.assign("WFS_ERR_CFG_INVALID_HKEY");							break;
		case WFS_ERR_CFG_INVALID_NAME						: _str.assign("WFS_ERR_CFG_INVALID_NAME");							break;
		case WFS_ERR_CFG_INVALID_SUBKEY						: _str.assign("WFS_ERR_CFG_INVALID_SUBKEY");						break;
		case WFS_ERR_CFG_INVALID_VALUE						: _str.assign("WFS_ERR_CFG_INVALID_VALUE");							break;
		case WFS_ERR_CFG_KEY_NOT_EMPTY						: _str.assign("WFS_ERR_CFG_KEY_NOT_EMPTY");							break;
		case WFS_ERR_CFG_NAME_TOO_LONG						: _str.assign("WFS_ERR_CFG_NAME_TOO_LONG");							break;
		case WFS_ERR_CFG_NO_MORE_ITEMS						: _str.assign("WFS_ERR_CFG_NO_MORE_ITEMS");							break;
		case WFS_ERR_CFG_VALUE_TOO_LONG						: _str.assign("WFS_ERR_CFG_VALUE_TOO_LONG");						break;
		case WFS_ERR_DEV_NOT_READY							: _str.assign("WFS_ERR_DEV_NOT_READY");								break;
		case WFS_ERR_HARDWARE_ERROR							: _str.assign("WFS_ERR_HARDWARE_ERROR");							break;
		case WFS_ERR_INTERNAL_ERROR							: _str.assign("WFS_ERR_INTERNAL_ERROR");							break;
		case WFS_ERR_INVALID_ADDRESS						: _str.assign("WFS_ERR_INVALID_ADDRESS");							break;
		case WFS_ERR_INVALID_APP_HANDLE						: _str.assign("WFS_ERR_INVALID_APP_HANDLE");						break;
		case WFS_ERR_INVALID_BUFFER							: _str.assign("WFS_ERR_INVALID_BUFFER");							break;
		case WFS_ERR_INVALID_CATEGORY						: _str.assign("WFS_ERR_INVALID_CATEGORY");							break;
		case WFS_ERR_INVALID_COMMAND						: _str.assign("WFS_ERR_INVALID_COMMAND");							break;
		case WFS_ERR_INVALID_EVENT_CLASS					: _str.assign("WFS_ERR_INVALID_EVENT_CLASS");						break;
		case WFS_ERR_INVALID_HSERVICE						: _str.assign("WFS_ERR_INVALID_HSERVICE");							break;
		case WFS_ERR_INVALID_HPROVIDER						: _str.assign("WFS_ERR_INVALID_HPROVIDER");							break;
		case WFS_ERR_INVALID_HWND							: _str.assign("WFS_ERR_INVALID_HWND");								break;
		case WFS_ERR_INVALID_HWNDREG						: _str.assign("WFS_ERR_INVALID_HWNDREG");							break;
		case WFS_ERR_INVALID_POINTER						: _str.assign("WFS_ERR_INVALID_POINTER");							break;
		case WFS_ERR_INVALID_REQ_ID							: _str.assign("WFS_ERR_INVALID_REQ_ID");							break;
		case WFS_ERR_INVALID_RESULT							: _str.assign("WFS_ERR_INVALID_RESULT");							break;
		case WFS_ERR_INVALID_SERVPROV						: _str.assign("WFS_ERR_INVALID_SERVPROV");							break;
		case WFS_ERR_INVALID_TIMER							: _str.assign("WFS_ERR_INVALID_TIMER");								break;
		case WFS_ERR_INVALID_TRACELEVEL						: _str.assign("WFS_ERR_INVALID_TRACELEVEL");						break;
		case WFS_ERR_LOCKED									: _str.assign("WFS_ERR_LOCKED");									break;
		case WFS_ERR_NO_BLOCKING_CALL						: _str.assign("WFS_ERR_NO_BLOCKING_CALL");							break;
		case WFS_ERR_NO_SERVPROV							: _str.assign("WFS_ERR_NO_SERVPROV");								break;
		case WFS_ERR_NO_SUCH_THREAD							: _str.assign("WFS_ERR_NO_SUCH_THREAD");							break;
		case WFS_ERR_NO_TIMER								: _str.assign("WFS_ERR_NO_TIMER");									break;
		case WFS_ERR_NOT_LOCKED								: _str.assign("WFS_ERR_NOT_LOCKED");								break;
		case WFS_ERR_NOT_OK_TO_UNLOAD						: _str.assign("WFS_ERR_NOT_OK_TO_UNLOAD");							break;
		case WFS_ERR_NOT_STARTED							: _str.assign("WFS_ERR_NOT_STARTED");								break;
		case WFS_ERR_NOT_REGISTERED							: _str.assign("WFS_ERR_NOT_REGISTERED");							break;
		case WFS_ERR_OP_IN_PROGRESS							: _str.assign("WFS_ERR_OP_IN_PROGRESS");							break;
		case WFS_ERR_OUT_OF_MEMORY							: _str.assign("WFS_ERR_OUT_OF_MEMORY");								break;
		case WFS_ERR_SERVICE_NOT_FOUND						: _str.assign("WFS_ERR_SERVICE_NOT_FOUND");							break;
		case WFS_ERR_SPI_VER_TOO_HIGH						: _str.assign("WFS_ERR_SPI_VER_TOO_HIGH");							break;
		case WFS_ERR_SPI_VER_TOO_LOW						: _str.assign("WFS_ERR_SPI_VER_TOO_LOW");							break;
		case WFS_ERR_SRVC_VER_TOO_HIGH						: _str.assign("WFS_ERR_SRVC_VER_TOO_HIGH");							break;
		case WFS_ERR_SRVC_VER_TOO_LOW						: _str.assign("WFS_ERR_SRVC_VER_TOO_LOW");							break;
		case WFS_ERR_TIMEOUT								: _str.assign("WFS_ERR_TIMEOUT");									break;
		case WFS_ERR_UNSUPP_CATEGORY						: _str.assign("WFS_ERR_UNSUPP_CATEGORY");							break;
		case WFS_ERR_UNSUPP_COMMAND							: _str.assign("WFS_ERR_UNSUPP_COMMAND");							break;
		case WFS_ERR_VERSION_ERROR_IN_SRVC					: _str.assign("WFS_ERR_VERSION_ERROR_IN_SRVC");						break;
		case WFS_ERR_INVALID_DATA							: _str.assign("WFS_ERR_INVALID_DATA");								break;
		case WFS_ERR_SOFTWARE_ERROR							: _str.assign("WFS_ERR_SOFTWARE_ERROR");							break;
		case WFS_ERR_CONNECTION_LOST						: _str.assign("WFS_ERR_CONNECTION_LOST");							break;
		case WFS_ERR_USER_ERROR								: _str.assign("WFS_ERR_USER_ERROR");								break;
		case WFS_ERR_UNSUPP_DATA							: _str.assign("WFS_ERR_UNSUPP_DATA");								break;
																																
		// PTR																													
		case WFS_ERR_PTR_FORMNOTFOUND						: _str.assign("WFS_ERR_PTR_FORMNOTFOUND");							break;
		case WFS_ERR_PTR_FIELDNOTFOUND						: _str.assign("WFS_ERR_PTR_FIELDNOTFOUND");							break;
		case WFS_ERR_PTR_NOMEDIAPRESENT						: _str.assign("WFS_ERR_PTR_NOMEDIAPRESENT");						break;
		case WFS_ERR_PTR_READNOTSUPPORTED					: _str.assign("WFS_ERR_PTR_READNOTSUPPORTED");						break;
		case WFS_ERR_PTR_FLUSHFAIL							: _str.assign("WFS_ERR_PTR_FLUSHFAIL");								break;
		case WFS_ERR_PTR_MEDIAOVERFLOW						: _str.assign("WFS_ERR_PTR_MEDIAOVERFLOW");							break;
		case WFS_ERR_PTR_FIELDSPECFAILURE					: _str.assign("WFS_ERR_PTR_FIELDSPECFAILURE");						break;
		case WFS_ERR_PTR_FIELDERROR							: _str.assign("WFS_ERR_PTR_FIELDERROR");							break;
		case WFS_ERR_PTR_MEDIANOTFOUND						: _str.assign("WFS_ERR_PTR_MEDIANOTFOUND");							break;
		case WFS_ERR_PTR_EXTENTNOTSUPPORTED					: _str.assign("WFS_ERR_PTR_EXTENTNOTSUPPORTED");					break;
		case WFS_ERR_PTR_MEDIAINVALID						: _str.assign("WFS_ERR_PTR_MEDIAINVALID");							break;
		case WFS_ERR_PTR_FORMINVALID						: _str.assign("WFS_ERR_PTR_FORMINVALID");							break;
		case WFS_ERR_PTR_FIELDINVALID						: _str.assign("WFS_ERR_PTR_FIELDINVALID");							break;
		case WFS_ERR_PTR_MEDIASKEWED						: _str.assign("WFS_ERR_PTR_MEDIASKEWED");							break;
		case WFS_ERR_PTR_RETRACTBINFULL						: _str.assign("WFS_ERR_PTR_RETRACTBINFULL");						break;
		case WFS_ERR_PTR_STACKERFULL						: _str.assign("WFS_ERR_PTR_STACKERFULL");							break;
		case WFS_ERR_PTR_PAGETURNFAIL						: _str.assign("WFS_ERR_PTR_PAGETURNFAIL");							break;
		case WFS_ERR_PTR_MEDIATURNFAIL						: _str.assign("WFS_ERR_PTR_MEDIATURNFAIL");							break;
		case WFS_ERR_PTR_SHUTTERFAIL						: _str.assign("WFS_ERR_PTR_SHUTTERFAIL");							break;
		case WFS_ERR_PTR_MEDIAJAMMED						: _str.assign("WFS_ERR_PTR_MEDIAJAMMED");							break;
		case WFS_ERR_PTR_FILE_IO_ERROR						: _str.assign("WFS_ERR_PTR_FILE_IO_ERROR");							break;
		case WFS_ERR_PTR_CHARSETDATA						: _str.assign("WFS_ERR_PTR_CHARSETDATA");							break;
		case WFS_ERR_PTR_PAPERJAMMED						: _str.assign("WFS_ERR_PTR_PAPERJAMMED");							break;
		case WFS_ERR_PTR_PAPEROUT							: _str.assign("WFS_ERR_PTR_PAPEROUT");								break;
		case WFS_ERR_PTR_INKOUT								: _str.assign("WFS_ERR_PTR_INKOUT");								break;
		case WFS_ERR_PTR_TONEROUT							: _str.assign("WFS_ERR_PTR_TONEROUT");								break;
		case WFS_ERR_PTR_LAMPINOP							: _str.assign("WFS_ERR_PTR_LAMPINOP");								break;
		case WFS_ERR_PTR_SOURCEINVALID						: _str.assign("WFS_ERR_PTR_SOURCEINVALID");							break;
		case WFS_ERR_PTR_SEQUENCEINVALID					: _str.assign("WFS_ERR_PTR_SEQUENCEINVALID");						break;
		case WFS_ERR_PTR_MEDIASIZE							: _str.assign("WFS_ERR_PTR_MEDIASIZE");								break;
																																
		// IDC																													
		case WFS_ERR_IDC_MEDIAJAM							: _str.assign("WFS_ERR_IDC_MEDIAJAM");								break;
		case WFS_ERR_IDC_NOMEDIA							: _str.assign("WFS_ERR_IDC_NOMEDIA");								break;
		case WFS_ERR_IDC_MEDIARETAINED						: _str.assign("WFS_ERR_IDC_MEDIARETAINED");							break;
		case WFS_ERR_IDC_RETAINBINFULL						: _str.assign("WFS_ERR_IDC_RETAINBINFULL");							break;
		case WFS_ERR_IDC_INVALIDDATA						: _str.assign("WFS_ERR_IDC_INVALIDDATA");							break;
		case WFS_ERR_IDC_INVALIDMEDIA						: _str.assign("WFS_ERR_IDC_INVALIDMEDIA");							break;
		case WFS_ERR_IDC_FORMNOTFOUND						: _str.assign("WFS_ERR_IDC_FORMNOTFOUND");							break;
		case WFS_ERR_IDC_FORMINVALID						: _str.assign("WFS_ERR_IDC_FORMINVALID");							break;
		case WFS_ERR_IDC_DATASYNTAX							: _str.assign("WFS_ERR_IDC_DATASYNTAX");							break;
		case WFS_ERR_IDC_SHUTTERFAIL						: _str.assign("WFS_ERR_IDC_SHUTTERFAIL");							break;
		case WFS_ERR_IDC_SECURITYFAIL						: _str.assign("WFS_ERR_IDC_SECURITYFAIL");							break;
		case WFS_ERR_IDC_PROTOCOLNOTSUPP					: _str.assign("WFS_ERR_IDC_PROTOCOLNOTSUPP");						break;
		case WFS_ERR_IDC_ATRNOTOBTAINED						: _str.assign("WFS_ERR_IDC_ATRNOTOBTAINED");						break;
		case WFS_ERR_IDC_INVALIDKEY							: _str.assign("WFS_ERR_IDC_INVALIDKEY");							break;
		case WFS_ERR_IDC_WRITE_METHOD						: _str.assign("WFS_ERR_IDC_WRITE_METHOD");							break;
		case WFS_ERR_IDC_CHIPPOWERNOTSUPP					: _str.assign("WFS_ERR_IDC_CHIPPOWERNOTSUPP");						break;
		case WFS_ERR_IDC_CARDTOOSHORT						: _str.assign("WFS_ERR_IDC_CARDTOOSHORT");							break;
		case WFS_ERR_IDC_CARDTOOLONG						: _str.assign("WFS_ERR_IDC_CARDTOOLONG");							break;
																																
		// CDM																													
		case WFS_ERR_CDM_INVALIDCURRENCY					: _str.assign("WFS_ERR_CDM_INVALIDCURRENCY");						break;
		case WFS_ERR_CDM_INVALIDTELLERID					: _str.assign("WFS_ERR_CDM_INVALIDTELLERID");						break;
		case WFS_ERR_CDM_CASHUNITERROR						: _str.assign("WFS_ERR_CDM_CASHUNITERROR");							break;
		case WFS_ERR_CDM_INVALIDDENOMINATION				: _str.assign("WFS_ERR_CDM_INVALIDDENOMINATION");					break;
		case WFS_ERR_CDM_INVALIDMIXNUMBER					: _str.assign("WFS_ERR_CDM_INVALIDMIXNUMBER");						break;
		case WFS_ERR_CDM_NOCURRENCYMIX						: _str.assign("WFS_ERR_CDM_NOCURRENCYMIX");							break;
		case WFS_ERR_CDM_NOTDISPENSABLE						: _str.assign("WFS_ERR_CDM_NOTDISPENSABLE");						break;
		case WFS_ERR_CDM_TOOMANYITEMS						: _str.assign("WFS_ERR_CDM_TOOMANYITEMS");							break;
		case WFS_ERR_CDM_UNSUPPOSITION						: _str.assign("WFS_ERR_CDM_UNSUPPOSITION");							break;
		case WFS_ERR_CDM_SAFEDOOROPEN						: _str.assign("WFS_ERR_CDM_SAFEDOOROPEN");							break;
		case WFS_ERR_CDM_SHUTTERNOTOPEN						: _str.assign("WFS_ERR_CDM_SHUTTERNOTOPEN");						break;
		case WFS_ERR_CDM_SHUTTEROPEN						: _str.assign("WFS_ERR_CDM_SHUTTEROPEN");							break;
		case WFS_ERR_CDM_SHUTTERCLOSED						: _str.assign("WFS_ERR_CDM_SHUTTERCLOSED");							break;
		case WFS_ERR_CDM_INVALIDCASHUNIT					: _str.assign("WFS_ERR_CDM_INVALIDCASHUNIT");						break;
		case WFS_ERR_CDM_NOITEMS							: _str.assign("WFS_ERR_CDM_NOITEMS");								break;
		case WFS_ERR_CDM_EXCHANGEACTIVE						: _str.assign("WFS_ERR_CDM_EXCHANGEACTIVE");						break;
		case WFS_ERR_CDM_NOEXCHANGEACTIVE					: _str.assign("WFS_ERR_CDM_NOEXCHANGEACTIVE");						break;
		case WFS_ERR_CDM_SHUTTERNOTCLOSED					: _str.assign("WFS_ERR_CDM_SHUTTERNOTCLOSED");						break;
		case WFS_ERR_CDM_PRERRORNOITEMS						: _str.assign("WFS_ERR_CDM_PRERRORNOITEMS");						break;
		case WFS_ERR_CDM_PRERRORITEMS						: _str.assign("WFS_ERR_CDM_PRERRORITEMS");							break;
		case WFS_ERR_CDM_PRERRORUNKNOWN						: _str.assign("WFS_ERR_CDM_PRERRORUNKNOWN");						break;
		case WFS_ERR_CDM_ITEMSTAKEN							: _str.assign("WFS_ERR_CDM_ITEMSTAKEN");							break;
		case WFS_ERR_CDM_INVALIDMIXTABLE					: _str.assign("WFS_ERR_CDM_INVALIDMIXTABLE");						break;
		case WFS_ERR_CDM_OUTPUTPOS_NOT_EMPTY				: _str.assign("WFS_ERR_CDM_OUTPUTPOS_NOT_EMPTY");					break;
		case WFS_ERR_CDM_INVALIDRETRACTPOSITION				: _str.assign("WFS_ERR_CDM_INVALIDRETRACTPOSITION");				break;
		case WFS_ERR_CDM_NOTRETRACTAREA						: _str.assign("WFS_ERR_CDM_NOTRETRACTAREA");						break;
		case WFS_ERR_CDM_NOCASHBOXPRESENT					: _str.assign("WFS_ERR_CDM_NOCASHBOXPRESENT");						break;
		case WFS_ERR_CDM_AMOUNTNOTINMIXTABLE				: _str.assign("WFS_ERR_CDM_AMOUNTNOTINMIXTABLE");					break;
		case WFS_ERR_CDM_ITEMSNOTTAKEN						: _str.assign("WFS_ERR_CDM_ITEMSNOTTAKEN");							break;
		case WFS_ERR_CDM_ITEMSLEFT							: _str.assign("WFS_ERR_CDM_ITEMSLEFT");								break;
																																
		// PIN																													
		case WFS_ERR_PIN_KEYNOTFOUND						: _str.assign("WFS_ERR_PIN_KEYNOTFOUND");							break;
		case WFS_ERR_PIN_MODENOTSUPPORTED					: _str.assign("WFS_ERR_PIN_MODENOTSUPPORTED");						break;
		case WFS_ERR_PIN_ACCESSDENIED						: _str.assign("WFS_ERR_PIN_ACCESSDENIED");							break;
		case WFS_ERR_PIN_INVALIDID							: _str.assign("WFS_ERR_PIN_INVALIDID");								break;
		case WFS_ERR_PIN_DUPLICATEKEY						: _str.assign("WFS_ERR_PIN_DUPLICATEKEY");							break;
		case WFS_ERR_PIN_KEYNOVALUE							: _str.assign("WFS_ERR_PIN_KEYNOVALUE");							break;
		case WFS_ERR_PIN_USEVIOLATION						: _str.assign("WFS_ERR_PIN_USEVIOLATION");							break;
		case WFS_ERR_PIN_NOPIN								: _str.assign("WFS_ERR_PIN_NOPIN");									break;
		case WFS_ERR_PIN_INVALIDKEYLENGTH					: _str.assign("WFS_ERR_PIN_INVALIDKEYLENGTH");						break;
		case WFS_ERR_PIN_KEYINVALID							: _str.assign("WFS_ERR_PIN_KEYINVALID");							break;
		case WFS_ERR_PIN_KEYNOTSUPPORTED					: _str.assign("WFS_ERR_PIN_KEYNOTSUPPORTED");						break;
		case WFS_ERR_PIN_NOACTIVEKEYS						: _str.assign("WFS_ERR_PIN_NOACTIVEKEYS");							break;
		case WFS_ERR_PIN_NOTERMINATEKEYS					: _str.assign("WFS_ERR_PIN_NOTERMINATEKEYS");						break;
		case WFS_ERR_PIN_MINIMUMLENGTH						: _str.assign("WFS_ERR_PIN_MINIMUMLENGTH");							break;
		case WFS_ERR_PIN_PROTOCOLNOTSUPP					: _str.assign("WFS_ERR_PIN_PROTOCOLNOTSUPP");						break;
		case WFS_ERR_PIN_INVALIDDATA						: _str.assign("WFS_ERR_PIN_INVALIDDATA");							break;
		case WFS_ERR_PIN_NOTALLOWED							: _str.assign("WFS_ERR_PIN_NOTALLOWED");							break;
		case WFS_ERR_PIN_NOKEYRAM							: _str.assign("WFS_ERR_PIN_NOKEYRAM");								break;
		case WFS_ERR_PIN_NOCHIPTRANSACTIVE					: _str.assign("WFS_ERR_PIN_NOCHIPTRANSACTIVE");						break;
		case WFS_ERR_PIN_ALGORITHMNOTSUPP					: _str.assign("WFS_ERR_PIN_ALGORITHMNOTSUPP");						break;
		case WFS_ERR_PIN_FORMATNOTSUPP						: _str.assign("WFS_ERR_PIN_FORMATNOTSUPP");							break;
		case WFS_ERR_PIN_HSMSTATEINVALID					: _str.assign("WFS_ERR_PIN_HSMSTATEINVALID");						break;
		case WFS_ERR_PIN_MACINVALID							: _str.assign("WFS_ERR_PIN_MACINVALID");							break;
		case WFS_ERR_PIN_PROTINVALID						: _str.assign("WFS_ERR_PIN_PROTINVALID");							break;
		case WFS_ERR_PIN_FORMATINVALID						: _str.assign("WFS_ERR_PIN_FORMATINVALID");							break;
		case WFS_ERR_PIN_CONTENTINVALID						: _str.assign("WFS_ERR_PIN_CONTENTINVALID");						break;
		case WFS_ERR_PIN_SIG_NOT_SUPP						: _str.assign("WFS_ERR_PIN_SIG_NOT_SUPP	");							break;
		case WFS_ERR_PIN_INVALID_MOD_LEN					: _str.assign("WFS_ERR_PIN_INVALID_MOD_LEN");						break;
		case WFS_ERR_PIN_INVALIDCERTSTATE					: _str.assign("WFS_ERR_PIN_INVALIDCERTSTATE");						break;
		case WFS_ERR_PIN_KEY_GENERATION_ERROR				: _str.assign("WFS_ERR_PIN_KEY_GENERATION_ERROR");					break;
		case WFS_ERR_PIN_EMV_VERIFY_FAILED					: _str.assign("WFS_ERR_PIN_EMV_VERIFY_FAILED");						break;
		case WFS_ERR_PIN_RANDOMINVALID						: _str.assign("WFS_ERR_PIN_RANDOMINVALID");							break;
		case WFS_ERR_PIN_SIGNATUREINVALID					: _str.assign("WFS_ERR_PIN_SIGNATUREINVALID");						break;
		case WFS_ERR_PIN_SNSCDINVALID						: _str.assign("WFS_ERR_PIN_SNSCDINVALID");							break;
		case WFS_ERR_PIN_NORSAKEYPAIR						: _str.assign("WFS_ERR_PIN_NORSAKEYPAIR");							break;
																																
		// CHK																													
		case WFS_ERR_CHK_FORMNOTFOUND						: _str.assign("WFS_ERR_CHK_FORMNOTFOUND");							break;
		case WFS_ERR_CHK_FORMINVALID						: _str.assign("WFS_ERR_CHK_FORMINVALID");							break;
		case WFS_ERR_CHK_MEDIANOTFOUND						: _str.assign("WFS_ERR_CHK_MEDIANOTFOUND");							break;
		case WFS_ERR_CHK_MEDIAINVALID						: _str.assign("WFS_ERR_CHK_MEDIAINVALID");							break;
		case WFS_ERR_CHK_MEDIAOVERFLOW						: _str.assign("WFS_ERR_CHK_MEDIAOVERFLOW");							break;
		case WFS_ERR_CHK_FIELDNOTFOUND						: _str.assign("WFS_ERR_CHK_FIELDNOTFOUND");							break;
		case WFS_ERR_CHK_FIELDINVALID						: _str.assign("WFS_ERR_CHK_FIELDINVALID");							break;
		case WFS_ERR_CHK_FIELDERROR							: _str.assign("WFS_ERR_CHK_FIELDERROR");							break;
		case WFS_ERR_CHK_REQDFIELDMISSING					: _str.assign("WFS_ERR_CHK_REQDFIELDMISSING");						break;
		case WFS_ERR_CHK_FIELDSPECFAILURE					: _str.assign("WFS_ERR_CHK_FIELDSPECFAILURE");						break;
		case WFS_ERR_CHK_CHARSETDATA						: _str.assign("WFS_ERR_CHK_CHARSETDATA");							break;
		case WFS_ERR_CHK_MEDIAJAM							: _str.assign("WFS_ERR_CHK_MEDIAJAM");								break;
		case WFS_ERR_CHK_SHUTTERFAIL						: _str.assign("WFS_ERR_CHK_SHUTTERFAIL");							break;
																																
		// DEP																													
		case WFS_ERR_DEP_DEPFULL							: _str.assign("WFS_ERR_DEP_DEPFULL");								break;
		case WFS_ERR_DEP_DEPJAMMED							: _str.assign("WFS_ERR_DEP_DEPJAMMED");								break;
		case WFS_ERR_DEP_ENVEMPTY							: _str.assign("WFS_ERR_DEP_ENVEMPTY");								break;
		case WFS_ERR_DEP_ENVJAMMED							: _str.assign("WFS_ERR_DEP_ENVJAMMED");								break;
		case WFS_ERR_DEP_ENVSIZE							: _str.assign("WFS_ERR_DEP_ENVSIZE");								break;
		case WFS_ERR_DEP_NOENV								: _str.assign("WFS_ERR_DEP_NOENV");									break;
		case WFS_ERR_DEP_PTRFAIL							: _str.assign("WFS_ERR_DEP_PTRFAIL");								break;
		case WFS_ERR_DEP_SHTNOTCLOSED						: _str.assign("WFS_ERR_DEP_SHTNOTCLOSED");							break;
		case WFS_ERR_DEP_SHTNOTOPENED						: _str.assign("WFS_ERR_DEP_SHTNOTOPENED");							break;
		case WFS_ERR_DEP_CONTMISSING						: _str.assign("WFS_ERR_DEP_CONTMISSING");							break;
		case WFS_ERR_DEP_DEPUNKNOWN							: _str.assign("WFS_ERR_DEP_DEPUNKNOWN");							break;
		case WFS_ERR_DEP_CHARSETNOTSUPP						: _str.assign("WFS_ERR_DEP_CHARSETNOTSUPP");						break;
		case WFS_ERR_DEP_TONEROUT							: _str.assign("WFS_ERR_DEP_TONEROUT");								break;
																																
		// TTU																													
		case WFS_ERR_TTU_FIELDERROR							: _str.assign("WFS_ERR_TTU_FIELDERROR");							break;
		case WFS_ERR_TTU_FIELDINVALID						: _str.assign("WFS_ERR_TTU_FIELDINVALID");							break;
		case WFS_ERR_TTU_FIELDNOTFOUND						: _str.assign("WFS_ERR_TTU_FIELDNOTFOUND");							break;
		case WFS_ERR_TTU_FIELDSPECFAILURE					: _str.assign("WFS_ERR_TTU_FIELDSPECFAILURE");						break;
		case WFS_ERR_TTU_FORMINVALID						: _str.assign("WFS_ERR_TTU_FORMINVALID");							break;
		case WFS_ERR_TTU_FORMNOTFOUND						: _str.assign("WFS_ERR_TTU_FORMNOTFOUND");							break;
		case WFS_ERR_TTU_INVALIDLED							: _str.assign("WFS_ERR_TTU_INVALIDLED");							break;
		case WFS_ERR_TTU_KEYCANCELED						: _str.assign("WFS_ERR_TTU_KEYCANCELED");							break;
		case WFS_ERR_TTU_MEDIAOVERFLOW						: _str.assign("WFS_ERR_TTU_MEDIAOVERFLOW");							break;
		case WFS_ERR_TTU_RESNOTSUPP							: _str.assign("WFS_ERR_TTU_RESNOTSUPP");							break;
		case WFS_ERR_TTU_CHARSETDATA						: _str.assign("WFS_ERR_TTU_CHARSETDATA");							break;
		case WFS_ERR_TTU_KEYINVALID							: _str.assign("WFS_ERR_TTU_KEYINVALID");							break;
		case WFS_ERR_TTU_KEYNOTSUPPORTED					: _str.assign("WFS_ERR_TTU_KEYNOTSUPPORTED");						break;
		case WFS_ERR_TTU_NOACTIVEKEYS						: _str.assign("WFS_ERR_TTU_NOACTIVEKEYS");							break;
																																
		// SIU																													
		case WFS_ERR_SIU_INVALID_PORT						: _str.assign("WFS_ERR_SIU_INVALID_PORT");							break;
		case WFS_ERR_SIU_SYNTAX								: _str.assign("WFS_ERR_SIU_SYNTAX");								break;
		case WFS_ERR_SIU_PORT_ERROR							: _str.assign("WFS_ERR_SIU_PORT_ERROR");							break;
																																
		// VDM																													
		// CAM																													
		case WFS_ERR_CAM_CAMNOTSUPP							: _str.assign("WFS_ERR_CAM_CAMNOTSUPP");							break;
		case WFS_ERR_CAM_MEDIAFULL							: _str.assign("WFS_ERR_CAM_MEDIAFULL");								break;
		case WFS_ERR_CAM_CAMINOP							: _str.assign("WFS_ERR_CAM_CAMINOP");								break;
		case WFS_ERR_CAM_CHARSETNOTSUPP						: _str.assign("WFS_ERR_CAM_CHARSETNOTSUPP");						break;
																																
		// CIM																													
		case WFS_ERR_CIM_INVALIDCURRENCY					: _str.assign("WFS_ERR_CIM_INVALIDCURRENCY");						break;
		case WFS_ERR_CIM_INVALIDTELLERID					: _str.assign("WFS_ERR_CIM_INVALIDTELLERID");						break;
		case WFS_ERR_CIM_CASHUNITERROR						: _str.assign("WFS_ERR_CIM_CASHUNITERROR");							break;
		case WFS_ERR_CIM_TOOMANYITEMS						: _str.assign("WFS_ERR_CIM_TOOMANYITEMS");							break;
		case WFS_ERR_CIM_UNSUPPOSITION						: _str.assign("WFS_ERR_CIM_UNSUPPOSITION");							break;
		case WFS_ERR_CIM_SAFEDOOROPEN						: _str.assign("WFS_ERR_CIM_SAFEDOOROPEN");							break;
		case WFS_ERR_CIM_SHUTTERNOTOPEN						: _str.assign("WFS_ERR_CIM_SHUTTERNOTOPEN");						break;
		case WFS_ERR_CIM_SHUTTEROPEN						: _str.assign("WFS_ERR_CIM_SHUTTEROPEN");							break;
		case WFS_ERR_CIM_SHUTTERCLOSED						: _str.assign("WFS_ERR_CIM_SHUTTERCLOSED");							break;
		case WFS_ERR_CIM_INVALIDCASHUNIT					: _str.assign("WFS_ERR_CIM_INVALIDCASHUNIT");						break;
		case WFS_ERR_CIM_NOITEMS							: _str.assign("WFS_ERR_CIM_NOITEMS");								break;
		case WFS_ERR_CIM_EXCHANGEACTIVE						: _str.assign("WFS_ERR_CIM_EXCHANGEACTIVE");						break;
		case WFS_ERR_CIM_NOEXCHANGEACTIVE					: _str.assign("WFS_ERR_CIM_NOEXCHANGEACTIVE");						break;
		case WFS_ERR_CIM_SHUTTERNOTCLOSED					: _str.assign("WFS_ERR_CIM_SHUTTERNOTCLOSED");						break;
		case WFS_ERR_CIM_ITEMSTAKEN							: _str.assign("WFS_ERR_CIM_ITEMSTAKEN");							break;
		case WFS_ERR_CIM_CASHINACTIVE						: _str.assign("WFS_ERR_CIM_CASHINACTIVE");							break;
		case WFS_ERR_CIM_NOCASHINACTIVE						: _str.assign("WFS_ERR_CIM_NOCASHINACTIVE");						break;
		case WFS_ERR_CIM_POSITION_NOT_EMPTY					: _str.assign("WFS_ERR_CIM_POSITION_NOT_EMPTY");					break;
		case WFS_ERR_CIM_INVALIDRETRACTPOSITION				: _str.assign("WFS_ERR_CIM_INVALIDRETRACTPOSITION");				break;
		case WFS_ERR_CIM_NOTRETRACTAREA						: _str.assign("WFS_ERR_CIM_NOTRETRACTAREA");						break;
																																
		default												: _str.assign("Unknown ERROR Code");								break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS Message Codes */																										
	/*=================================================================*/														
																																
	static std::string get_xfs_message(DWORD macro) noexcept																	
	{																															
		std::string _str{};																										
		switch (macro)																											
		{																														
		/****** Messages ********************************************************/											
		case WFS_OPEN_COMPLETE								: _str.assign("WFS_OPEN_COMPLETE");									break;
		case WFS_CLOSE_COMPLETE								: _str.assign("WFS_CLOSE_COMPLETE");								break;
		case WFS_LOCK_COMPLETE								: _str.assign("WFS_LOCK_COMPLETE");									break;
		case WFS_UNLOCK_COMPLETE							: _str.assign("WFS_UNLOCK_COMPLETE");								break;
		case WFS_REGISTER_COMPLETE							: _str.assign("WFS_REGISTER_COMPLETE");								break;
		case WFS_DEREGISTER_COMPLETE						: _str.assign("WFS_DEREGISTER_COMPLETE");							break;
		case WFS_GETINFO_COMPLETE							: _str.assign("WFS_GETINFO_COMPLETE");								break;
		case WFS_EXECUTE_COMPLETE							: _str.assign("WFS_EXECUTE_COMPLETE");								break;
		case WFS_EXECUTE_EVENT								: _str.assign("WFS_EXECUTE_EVENT");									break;
		case WFS_SERVICE_EVENT								: _str.assign("WFS_SERVICE_EVENT");									break;
		case WFS_USER_EVENT									: _str.assign("WFS_USER_EVENT");									break;
		case WFS_SYSTEM_EVENT								: _str.assign("WFS_SYSTEM_EVENT");									break;
		case WFS_TIMER_EVENT								: _str.assign("WFS_TIMER_EVENT");									break;

		/****** System Event IDs ************************************************/											
		case WFS_SYSE_UNDELIVERABLE_MSG						: _str.assign("WFS_SYSE_UNDELIVERABLE_MSG");						break;
		case WFS_SYSE_HARDWARE_ERROR						: _str.assign("WFS_SYSE_HARDWARE_ERROR");							break;
		case WFS_SYSE_VERSION_ERROR							: _str.assign("WFS_SYSE_VERSION_ERROR");							break;
		case WFS_SYSE_DEVICE_STATUS							: _str.assign("WFS_SYSE_DEVICE_STATUS");							break;
		case WFS_SYSE_APP_DISCONNECT						: _str.assign("WFS_SYSE_APP_DISCONNECT");							break;
		case WFS_SYSE_SOFTWARE_ERROR						: _str.assign("WFS_SYSE_SOFTWARE_ERROR");							break;
		case WFS_SYSE_USER_ERROR							: _str.assign("WFS_SYSE_USER_ERROR");								break;
		case WFS_SYSE_LOCK_REQUESTED						: _str.assign("WFS_SYSE_LOCK_REQUESTED");							break;
																																
		// PTR																													
		case WFS_EXEE_PTR_NOMEDIA							: _str.assign("WFS_EXEE_PTR_NOMEDIA");								break;
		case WFS_EXEE_PTR_MEDIAINSERTED						: _str.assign("WFS_EXEE_PTR_MEDIAINSERTED");						break;
		case WFS_EXEE_PTR_FIELDERROR						: _str.assign("WFS_EXEE_PTR_FIELDERROR");							break;
		case WFS_EXEE_PTR_FIELDWARNING						: _str.assign("WFS_EXEE_PTR_FIELDWARNING");							break;
		case WFS_USRE_PTR_RETRACTBINTHRESHOLD				: _str.assign("WFS_USRE_PTR_RETRACTBINTHRESHOLD");					break;
		case WFS_SRVE_PTR_MEDIATAKEN						: _str.assign("WFS_SRVE_PTR_MEDIATAKEN");							break;
		case WFS_USRE_PTR_PAPERTHRESHOLD					: _str.assign("WFS_USRE_PTR_PAPERTHRESHOLD");						break;
		case WFS_USRE_PTR_TONERTHRESHOLD					: _str.assign("WFS_USRE_PTR_TONERTHRESHOLD");						break;
		case WFS_SRVE_PTR_MEDIAINSERTED						: _str.assign("WFS_SRVE_PTR_MEDIAINSERTED");						break;
		case WFS_USRE_PTR_LAMPTHRESHOLD						: _str.assign("WFS_USRE_PTR_LAMPTHRESHOLD");						break;
		case WFS_USRE_PTR_INKTHRESHOLD						: _str.assign("WFS_USRE_PTR_INKTHRESHOLD");							break;
		case WFS_SRVE_PTR_MEDIADETECTED						: _str.assign("WFS_SRVE_PTR_MEDIADETECTED");						break;
																																
		// IDC																													
		case WFS_EXEE_IDC_INVALIDTRACKDATA					: _str.assign("WFS_EXEE_IDC_INVALIDTRACKDATA");						break;
		case WFS_EXEE_IDC_MEDIAINSERTED						: _str.assign("WFS_EXEE_IDC_MEDIAINSERTED");						break;
		case WFS_SRVE_IDC_MEDIAREMOVED						: _str.assign("WFS_SRVE_IDC_MEDIAREMOVED");							break;
		case WFS_SRVE_IDC_CARDACTION						: _str.assign("WFS_SRVE_IDC_CARDACTION");							break;
		case WFS_USRE_IDC_RETAINBINTHRESHOLD				: _str.assign("WFS_USRE_IDC_RETAINBINTHRESHOLD");					break;
		case WFS_EXEE_IDC_INVALIDMEDIA						: _str.assign("WFS_EXEE_IDC_INVALIDMEDIA");							break;
		case WFS_EXEE_IDC_MEDIARETAINED						: _str.assign("WFS_EXEE_IDC_MEDIARETAINED");						break;
		case WFS_SRVE_IDC_MEDIADETECTED						: _str.assign("WFS_SRVE_IDC_MEDIADETECTED");						break;
																																
		// CDM																													
		case WFS_SRVE_CDM_SAFEDOOROPEN						: _str.assign("WFS_SRVE_CDM_SAFEDOOROPEN");							break;
		case WFS_SRVE_CDM_SAFEDOORCLOSED					: _str.assign("WFS_SRVE_CDM_SAFEDOORCLOSED");						break;
		case WFS_USRE_CDM_CASHUNITTHRESHOLD					: _str.assign("WFS_USRE_CDM_CASHUNITTHRESHOLD");					break;
		case WFS_SRVE_CDM_CASHUNITINFOCHANGED				: _str.assign("WFS_SRVE_CDM_CASHUNITINFOCHANGED");					break;
		case WFS_SRVE_CDM_TELLERINFOCHANGED					: _str.assign("WFS_SRVE_CDM_TELLERINFOCHANGED");					break;
		case WFS_EXEE_CDM_DELAYEDDISPENSE					: _str.assign("WFS_EXEE_CDM_DELAYEDDISPENSE");						break;
		case WFS_EXEE_CDM_STARTDISPENSE						: _str.assign("WFS_EXEE_CDM_STARTDISPENSE");						break;
		case WFS_EXEE_CDM_CASHUNITERROR						: _str.assign("WFS_EXEE_CDM_CASHUNITERROR");						break;
		case WFS_SRVE_CDM_ITEMSTAKEN						: _str.assign("WFS_SRVE_CDM_ITEMSTAKEN");							break;
		case WFS_EXEE_CDM_PARTIALDISPENSE					: _str.assign("WFS_EXEE_CDM_PARTIALDISPENSE");						break;
		case WFS_EXEE_CDM_SUBDISPENSEOK						: _str.assign("WFS_EXEE_CDM_SUBDISPENSEOK");						break;
		case WFS_SRVE_CDM_ITEMSPRESENTED					: _str.assign("WFS_SRVE_CDM_ITEMSPRESENTED");						break;
		case WFS_SRVE_CDM_COUNTS_CHANGED					: _str.assign("WFS_SRVE_CDM_COUNTS_CHANGED");						break;
		case WFS_EXEE_CDM_INCOMPLETEDISPENSE				: _str.assign("WFS_EXEE_CDM_INCOMPLETEDISPENSE");					break;
		case WFS_EXEE_CDM_NOTEERROR							: _str.assign("WFS_EXEE_CDM_NOTEERROR");							break;
		case WFS_SRVE_CDM_MEDIADETECTED						: _str.assign("WFS_SRVE_CDM_MEDIADETECTED");						break;
																																
		// PIN																													
		case WFS_EXEE_PIN_KEY								: _str.assign("WFS_EXEE_PIN_KEY");									break;
		case WFS_SRVE_PIN_INITIALIZED						: _str.assign("WFS_SRVE_PIN_INITIALIZED");							break;
		case WFS_SRVE_PIN_ILLEGAL_KEY_ACCESS				: _str.assign("WFS_SRVE_PIN_ILLEGAL_KEY_ACCESS");					break;
		case WFS_SRVE_PIN_OPT_REQUIRED						: _str.assign("WFS_SRVE_PIN_OPT_REQUIRED");							break;
		case WFS_SRVE_PIN_HSM_TDATA_CHANGED					: _str.assign("WFS_SRVE_PIN_HSM_TDATA_CHANGED");					break;
		case WFS_SRVE_PIN_CERTIFICATE_CHANGE				: _str.assign("WFS_SRVE_PIN_CERTIFICATE_CHANGE");					break;
																																
		// CHK																													
		case WFS_EXEE_CHK_NOMEDIA							: _str.assign("WFS_EXEE_CHK_NOMEDIA");								break;
		case WFS_EXEE_CHK_MEDIAINSERTED						: _str.assign("WFS_EXEE_CHK_MEDIAINSERTED");						break;
		case WFS_SRVE_CHK_MEDIAINSERTED						: _str.assign("WFS_SRVE_CHK_MEDIAINSERTED");						break;
		case WFS_EXEE_CHK_FIELDERROR						: _str.assign("WFS_EXEE_CHK_FIELDERROR");							break;
		case WFS_EXEE_CHK_FIELDWARNING						: _str.assign("WFS_EXEE_CHK_FIELDWARNING");							break;
		case WFS_USRE_CHK_INKTHRESHOLD						: _str.assign("WFS_USRE_CHK_INKTHRESHOLD");							break;
		case WFS_SRVE_CHK_MEDIADETECTED						: _str.assign("WFS_SRVE_CHK_MEDIADETECTED");						break;
																																
		// DEP																													
		case WFS_SRVE_DEP_ENVTAKEN							: _str.assign("WFS_SRVE_DEP_ENVTAKEN");								break;
		case WFS_EXEE_DEP_ENVDEPOSITED						: _str.assign("WFS_EXEE_DEP_ENVDEPOSITED");							break;
		case WFS_EXEE_DEP_DEPOSITERROR						: _str.assign("WFS_EXEE_DEP_DEPOSITERROR");							break;
		case WFS_USRE_DEP_DEPTHRESHOLD						: _str.assign("WFS_USRE_DEP_DEPTHRESHOLD");							break;
		case WFS_USRE_DEP_TONERTHRESHOLD					: _str.assign("WFS_USRE_DEP_TONERTHRESHOLD");						break;
		case WFS_USRE_DEP_ENVTHRESHOLD						: _str.assign("WFS_USRE_DEP_ENVTHRESHOLD");							break;
		case WFS_SRVE_DEP_CONTINSERTED						: _str.assign("WFS_SRVE_DEP_CONTINSERTED");							break;
		case WFS_SRVE_DEP_CONTREMOVED						: _str.assign("WFS_SRVE_DEP_CONTREMOVED");							break;
		case WFS_SRVE_DEP_ENVINSERTED						: _str.assign("WFS_SRVE_DEP_ENVINSERTED");							break;
		case WFS_SRVE_DEP_MEDIADETECTED						: _str.assign("WFS_SRVE_DEP_MEDIADETECTED");						break;
																																
		// TTU																													
		case WFS_EXEE_TTU_FIELDERROR						: _str.assign("WFS_EXEE_TTU_FIELDERROR");							break;
		case WFS_EXEE_TTU_FIELDWARNING						: _str.assign("WFS_EXEE_TTU_FIELDWARNING");							break;
		case WFS_EXEE_TTU_KEY								: _str.assign("WFS_EXEE_TTU_KEY");									break;

		// SIU																													
		case WFS_SRVE_SIU_PORT_STATUS						: _str.assign("WFS_SRVE_SIU_PORT_STATUS");							break;
		case WFS_EXEE_SIU_PORT_ERROR						: _str.assign("WFS_EXEE_SIU_PORT_ERROR");							break;

		// VDM																													
		case WFS_SRVE_VDM_ENTER_MODE_REQ					: _str.assign("WFS_SRVE_VDM_ENTER_MODE_REQ");						break;
		case WFS_SRVE_VDM_EXIT_MODE_REQ						: _str.assign("WFS_SRVE_VDM_EXIT_MODE_REQ");						break;
		case WFS_SYSE_VDM_MODEENTERED						: _str.assign("WFS_SYSE_VDM_MODEENTERED");							break;
		case WFS_SYSE_VDM_MODEEXITED						: _str.assign("WFS_SYSE_VDM_MODEEXITED");							break;

		// CAM																													
		case WFS_USRE_CAM_MEDIATHRESHOLD					: _str.assign("WFS_USRE_CAM_MEDIATHRESHOLD");						break;
		case WFS_EXEE_CAM_INVALIDDATA						: _str.assign("WFS_EXEE_CAM_INVALIDDATA");							break;

		// CIM																													
		case WFS_SRVE_CIM_SAFEDOOROPEN						: _str.assign(" WFS_SRVE_CIM_SAFEDOOROPEN");						break;
		case WFS_SRVE_CIM_SAFEDOORCLOSED					: _str.assign(" WFS_SRVE_CIM_SAFEDOORCLOSED");						break;
		case WFS_USRE_CIM_CASHUNITTHRESHOLD					: _str.assign(" WFS_USRE_CIM_CASHUNITTHRESHOLD");					break;
		case WFS_SRVE_CIM_CASHUNITINFOCHANGED				: _str.assign(" WFS_SRVE_CIM_CASHUNITINFOCHANGED");					break;
		case WFS_SRVE_CIM_TELLERINFOCHANGED					: _str.assign(" WFS_SRVE_CIM_TELLERINFOCHANGED");					break;
		case WFS_EXEE_CIM_CASHUNITERROR						: _str.assign(" WFS_EXEE_CIM_CASHUNITERROR");						break;
		case WFS_SRVE_CIM_ITEMSTAKEN						: _str.assign(" WFS_SRVE_CIM_ITEMSTAKEN");							break;
		case WFS_SRVE_CIM_COUNTS_CHANGED					: _str.assign(" WFS_SRVE_CIM_COUNTS_CHANGED");						break;
		case WFS_EXEE_CIM_INPUTREFUSE						: _str.assign(" WFS_EXEE_CIM_INPUTREFUSE");							break;
		case WFS_SRVE_CIM_ITEMSPRESENTED					: _str.assign(" WFS_SRVE_CIM_ITEMSPRESENTED");						break;
		case WFS_SRVE_CIM_ITEMSINSERTED						: _str.assign(" WFS_SRVE_CIM_ITEMSINSERTED");						break;
		case WFS_EXEE_CIM_NOTEERROR							: _str.assign(" WFS_EXEE_CIM_NOTEERROR");							break;
		case WFS_EXEE_CIM_SUBCASHIN							: _str.assign(" WFS_EXEE_CIM_SUBCASHIN");							break;
		case WFS_SRVE_CIM_MEDIADETECTED						: _str.assign(" WFS_SRVE_CIM_MEDIADETECTED");						break;
		case WFS_EXEE_CIM_INPUT_P6							: _str.assign(" WFS_EXEE_CIM_INPUT_P6");							break;
																																
		default												: _str.assign("Unknown MESSAGE Code");								break;
		}
		return _str;
	}																															
																																
	/*=================================================================*/
	/* XFS General Macros */											
	/*=================================================================*/

	static std::string get_gen_fwDevice(DWORD macro) noexcept																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_STAT_DEVONLINE								: _str.assign("WFS_STAT_DEVONLINE");								break;
		case WFS_STAT_DEVOFFLINE							: _str.assign("WFS_STAT_DEVOFFLINE");								break;
		case WFS_STAT_DEVPOWEROFF							: _str.assign("WFS_STAT_DEVPOWEROFF");								break;
		case WFS_STAT_DEVNODEVICE							: _str.assign("WFS_STAT_DEVNODEVICE");								break;
		case WFS_STAT_DEVHWERROR							: _str.assign("WFS_STAT_DEVHWERROR");								break;
		case WFS_STAT_DEVUSERERROR							: _str.assign("WFS_STAT_DEVUSERERROR");								break;
		case WFS_STAT_DEVBUSY								: _str.assign("WFS_STAT_DEVBUSY");									break;
		default												: _str.assign("Unknown fwDevice");									break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS PTR Macros */																										
	/*=================================================================*/														
																																
	static std::string get_ptr_fwDevice(DWORD macro)																			
	{																															
		/* values of WFSPTRSTATUS.fwDevice */																					
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_PTR_DEVONLINE								: _str.assign("WFS_PTR_DEVONLINE");									break;
		case WFS_PTR_DEVOFFLINE								: _str.assign("WFS_PTR_DEVOFFLINE");								break;
		case WFS_PTR_DEVPOWEROFF							: _str.assign("WFS_PTR_DEVPOWEROFF");								break;
		case WFS_PTR_DEVNODEVICE							: _str.assign("WFS_PTR_DEVNODEVICE");								break;
		case WFS_PTR_DEVHWERROR								: _str.assign("WFS_PTR_DEVHWERROR");								break;
		case WFS_PTR_DEVUSERERROR							: _str.assign("WFS_PTR_DEVUSERERROR");								break;
		case WFS_PTR_DEVBUSY								: _str.assign("WFS_PTR_DEVBUSY");									break;
		default												: _str.assign("Unknown fwStatus");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRSTATUS.fwMedia and																						
	WFSPTRMEDIADETECTED.wPosition */																							
	static std::string get_ptr_fwMedia(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_PTR_MEDIAPRESENT							: _str.assign("WFS_PTR_MEDIAPRESENT");								break;
		case WFS_PTR_MEDIANOTPRESENT						: _str.assign("WFS_PTR_MEDIANOTPRESENT");							break;
		case WFS_PTR_MEDIAJAMMED							: _str.assign("WFS_PTR_MEDIAJAMMED");								break;
		case WFS_PTR_MEDIANOTSUPP							: _str.assign("WFS_PTR_MEDIANOTSUPP");								break;
		case WFS_PTR_MEDIAUNKNOWN							: _str.assign("WFS_PTR_MEDIAUNKNOWN");								break;
		case WFS_PTR_MEDIAENTERING							: _str.assign("WFS_PTR_MEDIAENTERING");								break;
		case WFS_PTR_MEDIARETRACTED							: _str.assign("WFS_PTR_MEDIARETRACTED");							break;
		default												: _str.assign("Unknown fwMedia");									break;
		}																														
		return _str;																											
	}																															
																																
	/* Size and max index of fwPaper array */																					
	static std::string get_ptr_fwPaper_ArrayIndex(DWORD macro)																	
	{																															
		std::string _str; 																										
		switch (macro)																											
		{																														
		case WFS_PTR_SUPPLYUPPER							: _str.assign("WFS_PTR_SUPPLYUPPER");								break;
		case WFS_PTR_SUPPLYLOWER							: _str.assign("WFS_PTR_SUPPLYLOWER");								break;
		case WFS_PTR_SUPPLYEXTERNAL							: _str.assign("WFS_PTR_SUPPLYEXTERNAL");							break;
		case WFS_PTR_SUPPLYAUX								: _str.assign("WFS_PTR_SUPPLYAUX");									break;
		case WFS_PTR_SUPPLYAUX2								: _str.assign("WFS_PTR_SUPPLYAUX2");								break;
		case WFS_PTR_SUPPLYPARK								: _str.assign("WFS_PTR_SUPPLYPARK");								break;
		default												: _str.assign("Unknown fwPaper_ArrayIndex");						break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRSTATUS.fwPaper 																							
	and WFSPTRPAPERTHRESHOLD.wPaperThreshold */																					
	static std::string get_ptr_fwPaper(DWORD macro)																				
	{																															
		std::string _str; 																										
		switch (macro)																											
		{																														
		case WFS_PTR_PAPERFULL								: _str.assign("WFS_PTR_PAPERFULL");									break;
		case WFS_PTR_PAPERLOW								: _str.assign("WFS_PTR_PAPERLOW");									break;
		case WFS_PTR_PAPEROUT								: _str.assign("WFS_PTR_PAPEROUT");									break;
		case WFS_PTR_PAPERNOTSUPP							: _str.assign("WFS_PTR_PAPERNOTSUPP");								break;
		case WFS_PTR_PAPERUNKNOWN							: _str.assign("WFS_PTR_PAPERUNKNOWN");								break;
		case WFS_PTR_PAPERJAMMED							: _str.assign("WFS_PTR_PAPERJAMMED");								break;
		default												: _str.assign("Unknown fwPaper");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRSTATUS.fwToner */																						
	static std::string get_ptr_fwToner(DWORD macro)																				
	{																															
		std::string _str; 																										
		switch (macro)																											
		{																														
		case WFS_PTR_TONERFULL								: _str.assign("WFS_PTR_TONERFULL");									break;
		case WFS_PTR_TONERLOW								: _str.assign("WFS_PTR_TONERLOW");									break;
		case WFS_PTR_TONEROUT								: _str.assign("WFS_PTR_TONEROUT");									break;
		case WFS_PTR_TONERNOTSUPP							: _str.assign("WFS_PTR_TONERNOTSUPP");								break;
		case WFS_PTR_TONERUNKNOWN							: _str.assign("WFS_PTR_TONERUNKNOWN");								break;
		default												: _str.assign("Unknown fwToner");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRSTATUS.fwInk */																							
	static std::string get_ptr_fwInk(DWORD macro)																				
	{																															
		std::string _str; 																										
		switch (macro)																											
		{																														
		case WFS_PTR_INKFULL								: _str.assign("WFS_PTR_INKFULL");									break;
		case WFS_PTR_INKLOW									: _str.assign("WFS_PTR_INKLOW");									break;
		case WFS_PTR_INKOUT									: _str.assign("WFS_PTR_INKOUT");									break;
		case WFS_PTR_INKNOTSUPP								: _str.assign("WFS_PTR_INKNOTSUPP");								break;
		case WFS_PTR_INKUNKNOWN								: _str.assign("WFS_PTR_INKUNKNOWN");								break;
		default												: _str.assign("Unknown fwInk");										break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRSTATUS.fwLamp */																							
	static std::string get_ptr_fwLamp(DWORD macro)																				
	{																															
		std::string _str; 																										
		switch (macro)																											
		{																														
		case WFS_PTR_LAMPOK									: _str.assign("WFS_PTR_LAMPOK");									break;
		case WFS_PTR_LAMPFADING								: _str.assign("WFS_PTR_LAMPFADING");								break;
		case WFS_PTR_LAMPINOP								: _str.assign("WFS_PTR_LAMPINOP");									break;
		case WFS_PTR_LAMPNOTSUPP							: _str.assign("WFS_PTR_LAMPNOTSUPP");								break;
		case WFS_PTR_LAMPUNKNOWN							: _str.assign("WFS_PTR_LAMPUNKNOWN");								break;
		default												: _str.assign("Unknown fwLamp");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRSTATUS.fwRetractBin and 																					
	WFSPTRBINTHRESHOLD.wRetractBin */																							
	static std::string get_ptr_fwRetractBin(DWORD macro)																		
	{																															
		std::string _str; 																										
		switch (macro)																											
		{																														
		case WFS_PTR_RETRACTBINOK							: _str.assign("WFS_PTR_RETRACTBINOK");								break;
		case WFS_PTR_RETRACTBINFULL							: _str.assign("WFS_PTR_RETRACTBINFULL");							break;
		case WFS_PTR_RETRACTNOTSUPP							: _str.assign("WFS_PTR_RETRACTNOTSUPP");							break;
		case WFS_PTR_RETRACTUNKNOWN							: _str.assign("WFS_PTR_RETRACTUNKNOWN");							break;
		case WFS_PTR_RETRACTBINHIGH							: _str.assign("WFS_PTR_RETRACTBINHIGH");							break;
		default												: _str.assign("Unknown fwRetractBin");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwType */																							
	static std::string get_ptr_fwType(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_TYPERECEIPT)					_str.append("WFS_PTR_TYPERECEIPT ");								
		if (macro & WFS_PTR_TYPEPASSBOOK)					_str.append("WFS_PTR_TYPEPASSBOOK ");								
		if (macro & WFS_PTR_TYPEJOURNAL)					_str.append("WFS_PTR_TYPEJOURNAL ");								
		if (macro & WFS_PTR_TYPEDOCUMENT)					_str.append("WFS_PTR_TYPEDOCUMENT ");								
		if (macro & WFS_PTR_TYPESCANNER)					_str.append("WFS_PTR_TYPESCANNER ");								
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.wResolution, 																						
	WFSPTRPRINTFORM.wResolution */																								
	static std::string get_ptr_wResolution(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_RESLOW)							_str.append("WFS_PTR_RESLOW ");										
		if (macro & WFS_PTR_RESMED)							_str.append("WFS_PTR_RESMED ");										
		if (macro & WFS_PTR_RESHIGH)						_str.append("WFS_PTR_RESHIGH ");									
		if (macro & WFS_PTR_RESVERYHIGH)					_str.append("WFS_PTR_RESVERYHIGH ");								
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwReadForm */																						
	static std::string get_ptr_fwReadForm(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_READOCR)						_str.append("WFS_PTR_READOCR ");									
		if (macro & WFS_PTR_READMICR)						_str.append("WFS_PTR_READMICR ");									
		if (macro & WFS_PTR_READMSF)						_str.append("WFS_PTR_READMSF ");									
		if (macro & WFS_PTR_READBARCODE)					_str.append("WFS_PTR_READBARCODE ");								
		if (macro & WFS_PTR_READPAGEMARK)					_str.append("WFS_PTR_READPAGEMARK ");								
		if (macro & WFS_PTR_READIMAGE)						_str.append("WFS_PTR_READIMAGE ");									
		if (macro & WFS_PTR_READEMPTYLINE)					_str.append("WFS_PTR_READEMPTYLINE ");								
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwWriteForm */																						
	static std::string get_ptr_fwWriteForm(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_WRITETEXT)						_str.append("WFS_PTR_WRITETEXT ");									
		if (macro & WFS_PTR_WRITEGRAPHICS)					_str.append("WFS_PTR_WRITEGRAPHICS ");								
		if (macro & WFS_PTR_WRITEOCR)						_str.append("WFS_PTR_WRITEOCR ");									
		if (macro & WFS_PTR_WRITEMICR)						_str.append("WFS_PTR_WRITEMICR ");									
		if (macro & WFS_PTR_WRITEMSF)						_str.append("WFS_PTR_WRITEMSF ");									
		if (macro & WFS_PTR_WRITEBARCODE)					_str.append("WFS_PTR_WRITEBARCODE ");								
		if (macro & WFS_PTR_WRITESTAMP)						_str.append("WFS_PTR_WRITESTAMP ");									
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwExtents */																						
	static std::string get_ptr_fwExtents(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_EXTHORIZONTAL)					_str.append("WFS_PTR_EXTHORIZONTAL ");								
		if (macro & WFS_PTR_EXTVERTICAL)					_str.append("WFS_PTR_EXTVERTICAL ");								
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwControl, dwMediaControl */																		
	static std::string get_ptr_dwMediaControl(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_CTRLEJECT)						_str.append("WFS_PTR_CTRLEJECT ");									
		if (macro & WFS_PTR_CTRLPERFORATE)					_str.append("WFS_PTR_CTRLPERFORATE ");								
		if (macro & WFS_PTR_CTRLCUT)						_str.append("WFS_PTR_CTRLCUT ");									
		if (macro & WFS_PTR_CTRLSKIP)						_str.append("WFS_PTR_CTRLSKIP ");									
		if (macro & WFS_PTR_CTRLFLUSH)						_str.append("WFS_PTR_CTRLFLUSH ");									
		if (macro & WFS_PTR_CTRLRETRACT)					_str.append("WFS_PTR_CTRLRETRACT ");								
		if (macro & WFS_PTR_CTRLSTACK)						_str.append("WFS_PTR_CTRLSTACK ");									
		if (macro & WFS_PTR_CTRLPARTIALCUT)					_str.append("WFS_PTR_CTRLPARTIALCUT ");								
		if (macro & WFS_PTR_CTRLALARM)						_str.append("WFS_PTR_CTRLALARM ");									
		if (macro & WFS_PTR_CTRLATPFORWARD)					_str.append("WFS_PTR_CTRLATPFORWARD ");								
		if (macro & WFS_PTR_CTRLATPBACKWARD)				_str.append("WFS_PTR_CTRLATPBACKWARD ");							
		if (macro & WFS_PTR_CTRLTURNMEDIA)					_str.append("WFS_PTR_CTRLTURNMEDIA ");								
		if (macro & WFS_PTR_CTRLSTAMP)						_str.append("WFS_PTR_CTRLSTAMP ");									
		if (macro & WFS_PTR_CTRLPARK)						_str.append("WFS_PTR_CTRLPARK ");									
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwPaperSources,																						
	WFSFRMMEDIA.wPaperSources,																									
	WFSPTRPRINTFORM.wPaperSource and																							
	WFSPTRPAPERTHRESHOLD.wPaperSource */																						
	static std::string get_ptr_fwPaperSources(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_PAPERANY)						_str.append("WFS_PTR_PAPERANY ");									
		if (macro & WFS_PTR_PAPERUPPER)						_str.append("WFS_PTR_PAPERUPPER ");									
		if (macro & WFS_PTR_PAPERLOWER)						_str.append("WFS_PTR_PAPERLOWER ");									
		if (macro & WFS_PTR_PAPEREXTERNAL)					_str.append("WFS_PTR_PAPEREXTERNAL ");								
		if (macro & WFS_PTR_PAPERAUX)						_str.append("WFS_PTR_PAPERAUX ");									
		if (macro & WFS_PTR_PAPERAUX2)						_str.append("WFS_PTR_PAPERAUX2 ");									
		if (macro & WFS_PTR_PAPERPARK)						_str.append("WFS_PTR_PAPERPARK ");									
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwImageType,																						
	WFSPTRIMAGEREQUEST.wFrontImageFormat and																					
	WFSPTRIMAGEREQUEST.wBackImageFormat */																						
	static std::string get_ptr_fwImageType(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_IMAGETIF)						_str.append("WFS_PTR_IMAGETIF ");									
		if (macro & WFS_PTR_IMAGEWMF)						_str.append("WFS_PTR_IMAGEWMF ");									
		if (macro & WFS_PTR_IMAGEBMP)						_str.append("WFS_PTR_IMAGEBMP ");									
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwFrontImageColorFormat,																			
	WFSPTRCAPS.fwBackImageColorFormat,																							
	WFSPTRIMAGEREQUEST.wFrontImageColorFormat and																				
	WFSPTRIMAGEREQUEST.wBackImageColorFormat */																					
	static std::string get_ptr_fwFrontImageColorFormat(DWORD macro)																
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_IMAGECOLORBINARY)				_str.append("WFS_PTR_IMAGECOLORBINARY ");							
		if (macro & WFS_PTR_IMAGECOLORGRAYSCALE)			_str.append("WFS_PTR_IMAGECOLORGRAYSCALE ");						
		if (macro & WFS_PTR_IMAGECOLORFULL)					_str.append("WFS_PTR_IMAGECOLORFULL ");								
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwCodelineFormat and 																				
	WFSPTRIMAGEREQUEST.wCodelineFormat */																						
	static std::string get_ptr_fwCodelineFormat(DWORD macro)																	
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_CODELINECMC7)					_str.append("WFS_PTR_CODELINECMC7 ");								
		if (macro & WFS_PTR_CODELINEE13B)					_str.append("WFS_PTR_CODELINEE13B ");								
		if (macro & WFS_PTR_CODELINEOCR)					_str.append("WFS_PTR_CODELINEOCR ");								
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwImageSource,																						
	WFSPTRIMAGEREQUEST.fwImageSource and																						
	WFSPTRIMAGE.wImageSource */																									
	static std::string get_ptr_fwImageSource(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_IMAGEFRONT)						_str.append("WFS_PTR_IMAGEFRONT ");									
		if (macro & WFS_PTR_IMAGEBACK)						_str.append("WFS_PTR_IMAGEBACK ");									
		if (macro & WFS_PTR_CODELINE)						_str.append("WFS_PTR_CODELINE ");									
		return _str;																											
	}																															
																																
	/* values of WFSPTRCAPS.fwCharSupport, WFSFRMHEADER.fwCharSupport */														
	static std::string get_ptr_fwCharSupport(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PTR_ASCII)							_str.append("WFS_PTR_ASCII ");										
		if (macro & WFS_PTR_UNICODE)						_str.append("WFS_PTR_UNICODE ");									
		return _str;																											
	}																															
																																
	/* values of WFSFRMHEADER.wBase, WFSFRMMEDIA.wBase, WFSPTRMEDIAUNIT.wBase */												
	static std::string get_ptr_wBase(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_INCH									: _str.assign("WFS_FRM_INCH");										break;
		case WFS_FRM_MM										: _str.assign("WFS_FRM_MM");										break;
		case WFS_FRM_ROWCOLUMN								: _str.assign("WFS_FRM_ROWCOLUMN");									break;
		default												: _str.assign("Unknown wBase");										break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSFRMHEADER.wAlignment */																						
	static std::string get_ptr_wFRMHeaderAlignment(DWORD macro)																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_TOPLEFT								: _str.assign("WFS_FRM_TOPLEFT");									break;
		case WFS_FRM_TOPRIGHT								: _str.assign("WFS_FRM_TOPRIGHT");									break;
		case WFS_FRM_BOTTOMLEFT								: _str.assign("WFS_FRM_BOTTOMLEFT");								break;
		case WFS_FRM_BOTTOMRIGHT							: _str.assign("WFS_FRM_BOTTOMRIGHT");								break;
		default												: _str.assign("Unknown wAlignment");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSFRMHEADER.wOrientation */																					
	static std::string get_ptr_wOrientation(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_PORTRAIT								: _str.assign("WFS_FRM_PORTRAIT");									break;
		case WFS_FRM_LANDSCAPE								: _str.assign("WFS_FRM_LANDSCAPE");									break;
		default												: _str.assign("Unknown wOrientation");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSFRMMEDIA.fwMediaType */																						
	static std::string get_ptr_fwMediaType(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_MEDIAGENERIC							: _str.assign("WFS_FRM_MEDIAGENERIC");								break;
		case WFS_FRM_MEDIAPASSBOOK							: _str.assign("WFS_FRM_MEDIAPASSBOOK");								break;
		case WFS_FRM_MEDIAMULTIPART							: _str.assign("WFS_FRM_MEDIAMULTIPART");							break;
		default												: _str.assign("Unknown fwMediaType");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSFRMMEDIA.fwFoldType */																						
	static std::string get_ptr_fwFoldType(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_FOLDNONE								: _str.assign("WFS_FRM_FOLDNONE");									break;
		case WFS_FRM_FOLDHORIZONTAL							: _str.assign("WFS_FRM_FOLDHORIZONTAL");							break;
		case WFS_FRM_FOLDVERTICAL							: _str.assign("WFS_FRM_FOLDVERTICAL");								break;
		default												: _str.assign("Unknown fwFoldType");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSFRMFIELD.fwType */																							
	static std::string get_ptr_fwFrmFieldType(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_FIELDTEXT								: _str.assign("WFS_FRM_FIELDTEXT");									break;
		case WFS_FRM_FIELDMICR								: _str.assign("WFS_FRM_FIELDMICR");									break;
		case WFS_FRM_FIELDOCR								: _str.assign("WFS_FRM_FIELDOCR");									break;
		case WFS_FRM_FIELDMSF								: _str.assign("WFS_FRM_FIELDMSF");									break;
		case WFS_FRM_FIELDBARCODE							: _str.assign("WFS_FRM_FIELDBARCODE");								break;
		case WFS_FRM_FIELDGRAPHIC							: _str.assign("WFS_FRM_FIELDGRAPHIC");								break;
		case WFS_FRM_FIELDPAGEMARK							: _str.assign("WFS_FRM_FIELDPAGEMARK");								break;
		default												: _str.assign("Unknown fwFoldType");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSFRMFIELD.fwClass */																							
	static std::string get_ptr_fwClass(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_CLASSSTATIC							: _str.assign("WFS_FRM_FIELDTEXT");									break;
		case WFS_FRM_CLASSOPTIONAL							: _str.assign("WFS_FRM_FIELDMICR");									break;
		case WFS_FRM_CLASSREQUIRED							: _str.assign("WFS_FRM_CLASSREQUIRED");								break;
		default												: _str.assign("Unknown fwClass");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSFRMFIELD.fwAccess */																						
	static std::string get_ptr_fwAccess(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_FRM_ACCESSREAD)						_str.append("WFS_FRM_ACCESSREAD ");									
		if (macro & WFS_FRM_ACCESSWRITE)					_str.append("WFS_FRM_ACCESSWRITE ");								
		return _str;																											
	}																															
																																
	/* values of WFSFRMFIELD.fwOverflow */																						
	static std::string get_ptr_fwOverflow(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_FRM_OVFTERMINATE							: _str.assign("WFS_FRM_OVFTERMINATE");								break;
		case WFS_FRM_OVFTRUNCATE							: _str.assign("WFS_FRM_OVFTRUNCATE");								break;
		case WFS_FRM_OVFBESTFIT								: _str.assign("WFS_FRM_OVFBESTFIT");								break;
		case WFS_FRM_OVFOVERWRITE							: _str.assign("WFS_FRM_OVFOVERWRITE");								break;
		case WFS_FRM_OVFWORDWRAP							: _str.assign("WFS_FRM_OVFWORDWRAP");								break;
		default												: _str.assign("Unknown fwOverflow");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRFIELDFAIL.wFailure */																					
	static std::string get_ptr_wFailure(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_PTR_FIELDREQUIRED							: _str.assign("WFS_PTR_FIELDREQUIRED");								break;
		case WFS_PTR_FIELDSTATICOVWR						: _str.assign("WFS_PTR_FIELDSTATICOVWR");							break;
		case WFS_PTR_FIELDOVERFLOW							: _str.assign("WFS_PTR_FIELDOVERFLOW");								break;
		case WFS_PTR_FIELDNOTFOUND							: _str.assign("WFS_PTR_FIELDNOTFOUND");								break;
		case WFS_PTR_FIELDNOTREAD							: _str.assign("WFS_PTR_FIELDNOTREAD");								break;
		case WFS_PTR_FIELDNOTWRITE							: _str.assign("WFS_PTR_FIELDNOTWRITE");								break;
		case WFS_PTR_FIELDHWERROR							: _str.assign("WFS_PTR_FIELDHWERROR");								break;
		case WFS_PTR_FIELDTYPENOTSUPPORTED					: _str.assign("WFS_PTR_FIELDTYPENOTSUPPORTED");						break;
		case WFS_PTR_FIELDGRAPHIC							: _str.assign("WFS_PTR_FIELDGRAPHIC");								break;
		case WFS_PTR_CHARSETFORM							: _str.assign("WFS_PTR_CHARSETFORM");								break;
		default												: _str.assign("Unknown wFailure");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRPRINTFORM.wAlignment */																					
	static std::string get_ptr_wPrintFormAlignment(DWORD macro)																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_PTR_ALNUSEFORMDEFN							: _str.assign("WFS_PTR_ALNUSEFORMDEFN");							break;
		case WFS_PTR_ALNTOPLEFT								: _str.assign("WFS_PTR_ALNTOPLEFT");								break;
		case WFS_PTR_ALNTOPRIGHT							: _str.assign("WFS_PTR_ALNTOPRIGHT");								break;
		case WFS_PTR_ALNBOTTOMLEFT							: _str.assign("WFS_PTR_ALNBOTTOMLEFT");								break;
		case WFS_PTR_ALNBOTTOMRIGHT							: _str.assign("WFS_PTR_ALNBOTTOMRIGHT");							break;
		default												: _str.assign("Unknown wAlignment");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRPRINTFORM.wOffsetX and WFSPTRPRINTFORM.wOffsetY */														
	static std::string get_ptr_wOffsetXY(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_PTR_OFFSETUSEFORMDEFN						: _str.assign("WFS_PTR_OFFSETUSEFORMDEFN");							break;
		default												: _str.assign("Unknown wOffsetXY");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRRAWDATA.wInputData */																					
	static std::string get_ptr_wInputData(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_PTR_NOINPUTDATA							: _str.assign("WFS_PTR_NOINPUTDATA");								break;
		case WFS_PTR_INPUTDATA								: _str.assign("WFS_PTR_INPUTDATA");									break;
		default												: _str.assign("Unknown wInputData");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPTRIMAGE.wStatus */																							
	static std::string get_ptr_wImageStatus(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_PTR_DATAOK									: _str.assign("WFS_PTR_DATAOK");									break;
		case WFS_PTR_DATASRCNOTSUPP							: _str.assign("WFS_PTR_DATASRCNOTSUPP");							break;
		case WFS_PTR_DATASRCMISSING							: _str.assign("WFS_PTR_DATASRCMISSING");							break;
		default												: _str.assign("Unknown wImageStatus");								break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS IDC Macros */																										
	/*=================================================================*/														
																																
	/* values of WFSIDCSTATUS.fwDevice */																						
	static std::string get_idc_fwDevice(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_DEVONLINE								: _str.assign("WFS_IDC_DEVONLINE");									break;
		case WFS_IDC_DEVOFFLINE								: _str.assign("WFS_IDC_DEVOFFLINE");								break;
		case WFS_IDC_DEVPOWEROFF							: _str.assign("WFS_IDC_DEVPOWEROFF");								break;
		case WFS_IDC_DEVNODEVICE							: _str.assign("WFS_IDC_DEVNODEVICE");								break;
		case WFS_IDC_DEVHWERROR								: _str.assign("WFS_IDC_DEVHWERROR");								break;
		case WFS_IDC_DEVUSERERROR							: _str.assign("WFS_IDC_DEVUSERERROR");								break;
		case WFS_IDC_DEVBUSY								: _str.assign("WFS_IDC_DEVBUSY");									break;
		default												: _str.assign("Unknown fwStatus");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCSTATUS.fwMedia, WFSIDCRETAINCARD.fwPosition, WFSIDCCARDACT.fwPosition */									
	static std::string get_idc_fwMedia(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_MEDIAPRESENT							: _str.assign("WFS_IDC_MEDIAPRESENT");								break;
		case WFS_IDC_MEDIANOTPRESENT						: _str.assign("WFS_IDC_MEDIANOTPRESENT");							break;
		case WFS_IDC_MEDIAJAMMED							: _str.assign("WFS_IDC_MEDIAJAMMED");								break;
		case WFS_IDC_MEDIANOTSUPP							: _str.assign("WFS_IDC_MEDIANOTSUPP");								break;
		case WFS_IDC_MEDIAUNKNOWN							: _str.assign("WFS_IDC_MEDIAUNKNOWN");								break;
		case WFS_IDC_MEDIAENTERING							: _str.assign("WFS_IDC_MEDIAENTERING");								break;
		case WFS_IDC_MEDIALATCHED							: _str.assign("WFS_IDC_MEDIALATCHED");								break;
		default												: _str.assign("Unknown fwMedia");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCSTATUS.fwRetainBin */																					
	static std::string get_idc_fwRetainBin(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_RETAINBINOK							: _str.assign("WFS_IDC_RETAINBINOK");								break;
		case WFS_IDC_RETAINNOTSUPP							: _str.assign("WFS_IDC_RETAINNOTSUPP");								break;
		case WFS_IDC_RETAINBINFULL							: _str.assign("WFS_IDC_RETAINBINFULL");								break;
		case WFS_IDC_RETAINBINHIGH							: _str.assign("WFS_IDC_RETAINBINHIGH");								break;
		default												: _str.assign("Unknown fwRetainBin");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCSTATUS.fwSecurity */																						
	static std::string get_idc_fwSecurity(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_SECNOTSUPP								: _str.assign("WFS_IDC_SECNOTSUPP");								break;
		case WFS_IDC_SECNOTREADY							: _str.assign("WFS_IDC_SECNOTREADY");								break;
		case WFS_IDC_SECOPEN								: _str.assign("WFS_IDC_SECOPEN");									break;
		default												: _str.assign("Unknown fwSecurity");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCSTATUS.fwChipPower */																					
	static std::string get_idc_fwStatusChipPower(DWORD macro)																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_CHIPONLINE								: _str.assign("WFS_IDC_CHIPONLINE");								break;
		case WFS_IDC_CHIPPOWEREDOFF							: _str.assign("WFS_IDC_CHIPPOWEREDOFF");							break;
		case WFS_IDC_CHIPBUSY								: _str.assign("WFS_IDC_CHIPBUSY");									break;
		case WFS_IDC_CHIPNODEVICE							: _str.assign("WFS_IDC_CHIPNODEVICE");								break;
		case WFS_IDC_CHIPHWERROR							: _str.assign("WFS_IDC_CHIPHWERROR");								break;
		case WFS_IDC_CHIPNOCARD								: _str.assign("WFS_IDC_CHIPNOCARD");								break;
		case WFS_IDC_CHIPNOTSUPP							: _str.assign("WFS_IDC_CHIPNOTSUPP");								break;
		case WFS_IDC_CHIPUNKNOWN							: _str.assign("WFS_IDC_CHIPUNKNOWN");								break;
		default												: _str.assign("Unknown fwChipPower");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCCAPS.fwType */																							
	static std::string get_idc_fwType(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_TYPEMOTOR								: _str.assign("WFS_IDC_TYPEMOTOR");									break;
		case WFS_IDC_TYPESWIPE								: _str.assign("WFS_IDC_TYPESWIPE");									break;
		case WFS_IDC_TYPEDIP								: _str.assign("WFS_IDC_TYPEDIP");									break;
		case WFS_IDC_TYPECONTACTLESS						: _str.assign("WFS_IDC_TYPECONTACTLESS");							break;
		case WFS_IDC_TYPELATCHEDDIP							: _str.assign("WFS_IDC_TYPELATCHEDDIP");							break;
		case WFS_IDC_TYPEPERMANENT							: _str.assign("WFS_IDC_TYPEPERMANENT");								break;
		default												: _str.assign("Unknown fwType");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCCAPS.fwReadTracks, WFSIDCCAPS.fwWriteTracks, WFSIDCCARDDATA.wDataSource */								
	static std::string get_idc_fwReadTracks(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_IDC_NOTSUPP)						_str.append("WFS_IDC_NOTSUPP ");									
		if (macro & WFS_IDC_TRACK1)							_str.append("WFS_IDC_TRACK1 ");										
		if (macro & WFS_IDC_TRACK2)							_str.append("WFS_IDC_TRACK2 ");										
		if (macro & WFS_IDC_TRACK3)							_str.append("WFS_IDC_TRACK3 ");										
		if (macro & WFS_IDC_CHIP)							_str.append("WFS_IDC_CHIP ");										
		if (macro & WFS_IDC_SECURITY)						_str.append("WFS_IDC_SECURITY ");									
		if (macro & WFS_IDC_FLUXINACTIVE)					_str.append("WFS_IDC_FLUXINACTIVE ");								
		if (macro & WFS_IDC_TRACK_WM)						_str.append("WFS_IDC_TRACK_WM ");									
		return _str;																											
	}																															
																																
	/* further values of WFSIDCCARDDATA.wDataSource */																			
	static std::string get_idc_wDataSource(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_IDC_NOTSUPP)						_str.append("WFS_IDC_NOTSUPP ");									
		if (macro & WFS_IDC_TRACK1)							_str.append("WFS_IDC_TRACK1 ");										
		if (macro & WFS_IDC_TRACK2)							_str.append("WFS_IDC_TRACK2 ");										
		if (macro & WFS_IDC_TRACK3)							_str.append("WFS_IDC_TRACK3 ");										
		if (macro & WFS_IDC_CHIP)							_str.append("WFS_IDC_CHIP ");										
		if (macro & WFS_IDC_SECURITY)						_str.append("WFS_IDC_SECURITY ");									
		if (macro & WFS_IDC_FLUXINACTIVE)					_str.append("WFS_IDC_FLUXINACTIVE ");								
		if (macro & WFS_IDC_TRACK_WM)						_str.append("WFS_IDC_TRACK_WM ");									
		return _str;																											
	}																															
																																
	/* values of WFSIDCCAPS.fwChipProtocols */																					
	static std::string get_idc_fwChipProtocols(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_IDC_CHIPT0)							_str.append("WFS_IDC_CHIPT0 ");										
		if (macro & WFS_IDC_CHIPT1)							_str.append("WFS_IDC_CHIPT1 ");										
		if (macro & WFS_IDC_CHIPT2)							_str.append("WFS_IDC_CHIPT2 ");										
		if (macro & WFS_IDC_CHIPT3)							_str.append("WFS_IDC_CHIPT3 ");										
		if (macro & WFS_IDC_CHIPT4)							_str.append("WFS_IDC_CHIPT4 ");										
		if (macro & WFS_IDC_CHIPT5)							_str.append("WFS_IDC_CHIPT5 ");										
		if (macro & WFS_IDC_CHIPT6)							_str.append("WFS_IDC_CHIPT6 ");										
		if (macro & WFS_IDC_CHIPT7)							_str.append("WFS_IDC_CHIPT7 ");										
		if (macro & WFS_IDC_CHIPT8)							_str.append("WFS_IDC_CHIPT8 ");										
		if (macro & WFS_IDC_CHIPT9)							_str.append("WFS_IDC_CHIPT9 ");										
		if (macro & WFS_IDC_CHIPT10)						_str.append("WFS_IDC_CHIPT10 ");									
		if (macro & WFS_IDC_CHIPT11)						_str.append("WFS_IDC_CHIPT11 ");									
		if (macro & WFS_IDC_CHIPT12)						_str.append("WFS_IDC_CHIPT12 ");									
		if (macro & WFS_IDC_CHIPT13)						_str.append("WFS_IDC_CHIPT13 ");									
		if (macro & WFS_IDC_CHIPT14)						_str.append("WFS_IDC_CHIPT14 ");									
		if (macro & WFS_IDC_CHIPT15)						_str.append("WFS_IDC_CHIPT15 ");									
		return _str;																											
	}																															
																																
	/* values of WFSIDCCAPS.fwSecType */																						
	static std::string get_idc_fwSecType(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_SECNOTSUPP								: _str.assign("WFS_IDC_SECNOTSUPP");								break;
		case WFS_IDC_SECMMBOX								: _str.assign("WFS_IDC_SECMMBOX");									break;
		case WFS_IDC_SECCIM86								: _str.assign("WFS_IDC_SECCIM86");									break;
		default												: _str.assign("Unknown fwSecType");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCCAPS.fwPowerOnOption, WFSIDCCAPS.fwPowerOffOption, */													
	static std::string get_idc_fwPowerOnOption(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_NOACTION								: _str.assign("WFS_IDC_NOACTION");									break;
		case WFS_IDC_EJECT									: _str.assign("WFS_IDC_EJECT");										break;
		case WFS_IDC_RETAIN									: _str.assign("WFS_IDC_RETAIN");									break;
		case WFS_IDC_EJECTTHENRETAIN						: _str.assign("WFS_IDC_EJECTTHENRETAIN");							break;
		case WFS_IDC_READPOSITION							: _str.assign("WFS_IDC_READPOSITION");								break;
		default												: _str.assign("Unknown fwPowerOnOption");							break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSIDCCAPS.fwWriteMode; WFSIDCWRITETRACK.fwWriteMethod, WFSIDCCARDDATA.fwWriteMethod */						
	static std::string get_idc_fwWriteMode(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_IDC_UNKNOWN)						_str.append("WFS_IDC_UNKNOWN ");									
		if (macro & WFS_IDC_LOCO)							_str.append("WFS_IDC_LOCO ");										
		if (macro & WFS_IDC_HICO)							_str.append("WFS_IDC_HICO ");										
		if (macro & WFS_IDC_AUTO)							_str.append("WFS_IDC_AUTO ");										
		return _str;																											
	}																															
																																
	/* values of WFSIDCCAPS.fwChipPower */																						
	static std::string get_idc_fwCapChipPower(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_IDC_CHIPPOWERCOLD)					_str.append("WFS_IDC_CHIPPOWERCOLD ");								
		if (macro & WFS_IDC_CHIPPOWERWARM)					_str.append("WFS_IDC_CHIPPOWERWARM ");								
		if (macro & WFS_IDC_CHIPPOWEROFF)					_str.append("WFS_IDC_CHIPPOWEROFF ");								
		return _str;																											
	}																															
																																
	/* values of WFSIDCFORM.fwAction */																							
	static std::string get_idc_fwAction(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_IDC_ACTIONREAD)						_str.append("WFS_IDC_ACTIONREAD ");									
		if (macro & WFS_IDC_ACTIONWRITE)					_str.append("WFS_IDC_ACTIONWRITE ");								
		return _str;																											
	}																															
																																
	/* values of WFSIDCTRACKEVENT.fwStatus, WFSIDCCARDDATA.wStatus */															
	static std::string get_idc_fwStatus(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_DATAOK									: _str.assign("WFS_IDC_DATAOK");									break;
		case WFS_IDC_DATAMISSING							: _str.assign("WFS_IDC_DATAMISSING");								break;
		case WFS_IDC_DATAINVALID							: _str.assign("WFS_IDC_DATAINVALID");								break;
		case WFS_IDC_DATATOOLONG							: _str.assign("WFS_IDC_DATATOOLONG");								break;
		case WFS_IDC_DATATOOSHORT							: _str.assign("WFS_IDC_DATATOOSHORT");								break;
		case WFS_IDC_DATASRCNOTSUPP							: _str.assign("WFS_IDC_DATASRCNOTSUPP");							break;
		case WFS_IDC_DATASRCMISSING							: _str.assign("WFS_IDC_DATASRCMISSING");							break;
		default												: _str.assign("Unknown fwTrackEventStatus");						break;
		}																														
		return _str;																											
	}																															
																																
	/* values WFSIDCCARDACT.wAction */																							
	static std::string get_idc_wAction(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_IDC_CARDRETAINED							: _str.assign("WFS_IDC_CARDRETAINED");								break;
		case WFS_IDC_CARDEJECTED							: _str.assign("WFS_IDC_CARDEJECTED");								break;
		case WFS_IDC_CARDREADPOSITION						: _str.assign("WFS_IDC_CARDREADPOSITION");							break;
		case WFS_IDC_CARDJAMMED								: _str.assign("WFS_IDC_CARDJAMMED");								break;
		default												: _str.assign("Unknown wAction");									break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS CDM Macros */																										
	/*=================================================================*/														
																																
	/* values of WFSCDMSTATUS.fwDevice */																						
	static std::string get_cdm_fwDevice(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_DEVONLINE								: _str.assign("WFS_CDM_DEVONLINE");									break;
		case WFS_CDM_DEVOFFLINE								: _str.assign("WFS_CDM_DEVOFFLINE");								break;
		case WFS_CDM_DEVPOWEROFF							: _str.assign("WFS_CDM_DEVPOWEROFF");								break;
		case WFS_CDM_DEVNODEVICE							: _str.assign("WFS_CDM_DEVNODEVICE");								break;
		case WFS_CDM_DEVHWERROR								: _str.assign("WFS_CDM_DEVHWERROR");								break;
		case WFS_CDM_DEVUSERERROR							: _str.assign("WFS_CDM_DEVUSERERROR");								break;
		case WFS_CDM_DEVBUSY								: _str.assign("WFS_CDM_DEVBUSY");									break;
		default												: _str.assign("Unknown fwStatus");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMSTATUS.fwSafeDoor */																						
	static std::string get_cdm_fwSafeDoor(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_DOORNOTSUPPORTED						: _str.assign("WFS_CDM_DOORNOTSUPPORTED");							break;
		case WFS_CDM_DOOROPEN								: _str.assign("WFS_CDM_DOOROPEN");									break;
		case WFS_CDM_DOORCLOSED								: _str.assign("WFS_CDM_DOORCLOSED");								break;
		case WFS_CDM_DOORUNKNOWN							: _str.assign("WFS_CDM_DOORUNKNOWN");								break;
		default												: _str.assign("Unknown fwSafeDoor");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMSTATUS.fwDispenser */																					
	static std::string get_cdm_fwDispenser(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_DISPOK									: _str.assign("WFS_CDM_DISPOK");									break;
		case WFS_CDM_DISPCUSTATE							: _str.assign("WFS_CDM_DISPCUSTATE");								break;
		case WFS_CDM_DISPCUSTOP								: _str.assign("WFS_CDM_DISPCUSTOP");								break;
		case WFS_CDM_DISPCUUNKNOWN							: _str.assign("WFS_CDM_DISPCUUNKNOWN");								break;
		default												: _str.assign("Unknown fwDispenser");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMSTATUS.fwIntermediateStacker */																			
	static std::string get_cdm_fwIntermediateStacker(DWORD macro)																
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_ISEMPTY								: _str.assign("WFS_CDM_ISEMPTY");									break;
		case WFS_CDM_ISNOTEMPTY								: _str.assign("WFS_CDM_ISNOTEMPTY");								break;
		case WFS_CDM_ISNOTEMPTYCUST							: _str.assign("WFS_CDM_ISNOTEMPTYCUST");							break;
		case WFS_CDM_ISUNKNOWN								: _str.assign("WFS_CDM_ISUNKNOWN");									break;
		case WFS_CDM_ISNOTSUPPORTED							: _str.assign("WFS_CDM_ISNOTSUPPORTED");							break;
		default												: _str.assign("Unknown fwIntermediateStacker");						break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMOUTPOS.fwShutter */																						
	static std::string get_cdm_fwShutter(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_SHTCLOSED								: _str.assign("WFS_CDM_SHTCLOSED");									break;
		case WFS_CDM_SHTOPEN								: _str.assign("WFS_CDM_SHTOPEN");									break;
		case WFS_CDM_SHTJAMMED								: _str.assign("WFS_CDM_SHTJAMMED");									break;
		case WFS_CDM_SHTUNKNOWN								: _str.assign("WFS_CDM_SHTUNKNOWN");								break;
		case WFS_CDM_SHTNOTSUPPORTED						: _str.assign("WFS_CDM_SHTNOTSUPPORTED");							break;
		default												: _str.assign("Unknown fwShutter");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMOUTPOS.fwPositionStatus */																				
	static std::string get_cdm_fwPositionStatus(DWORD macro)																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_PSEMPTY								: _str.assign("WFS_CDM_PSEMPTY");									break;
		case WFS_CDM_PSNOTEMPTY								: _str.assign("WFS_CDM_PSNOTEMPTY");								break;
		case WFS_CDM_PSUNKNOWN								: _str.assign("WFS_CDM_PSUNKNOWN");									break;
		case WFS_CDM_PSNOTSUPPORTED							: _str.assign("WFS_CDM_PSNOTSUPPORTED");							break;
		default												: _str.assign("Unknown fwPositionStatus");							break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMOUTPOS.fwTransport */																					
	static std::string get_cdm_fwTransport(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_TPOK									: _str.assign("WFS_CDM_TPOK");										break;
		case WFS_CDM_TPINOP									: _str.assign("WFS_CDM_TPINOP");									break;	
		case WFS_CDM_TPUNKNOWN								: _str.assign("WFS_CDM_TPUNKNOWN");									break;	
		case WFS_CDM_TPNOTSUPPORTED							: _str.assign("WFS_CDM_TPNOTSUPPORTED");							break;
		default												: _str.assign("Unknown fwTransport");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMOUTPOS.fwTransportStatus */																				
	static std::string get_cdm_fwTransportStatus(DWORD macro)																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_TPSTATEMPTY							: _str.assign("WFS_CDM_TPSTATEMPTY");								break;
		case WFS_CDM_TPSTATNOTEMPTY							: _str.assign("WFS_CDM_TPSTATNOTEMPTY");							break;
		case WFS_CDM_TPSTATNOTEMPTYCUST						: _str.assign("WFS_CDM_TPSTATNOTEMPTYCUST");						break;
		case WFS_CDM_TPSTATNOTEMPTY_UNK						: _str.assign("WFS_CDM_TPSTATNOTEMPTY_UNK");						break;
		case WFS_CDM_TPSTATNOTSUPPORTED						: _str.assign("WFS_CDM_TPSTATNOTSUPPORTED");						break;
		default												: _str.assign("Unknown fwTransportStatus");							break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMCAPS.fwType */																							
	static std::string get_cdm_fwType(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_TELLERBILL								: _str.assign("WFS_CDM_TELLERBILL");								break;
		case WFS_CDM_SELFSERVICEBILL						: _str.assign("WFS_CDM_SELFSERVICEBILL");							break;
		case WFS_CDM_TELLERCOIN								: _str.assign("WFS_CDM_TELLERCOIN");								break;
		case WFS_CDM_SELFSERVICECOIN						: _str.assign("WFS_CDM_SELFSERVICECOIN");							break;
		default												: _str.assign("Unknown fwType");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMCAPS.fwRetractAreas */																					
	/* values of WFSCDMRETRACT.usRetractArea */																					
	static std::string get_cdm_fwRetractAreas(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_CDM_RA_RETRACT)						_str.append("WFS_CDM_RA_RETRACT ");									
		if (macro & WFS_CDM_RA_TRANSPORT)					_str.append("WFS_CDM_RA_TRANSPORT ");								
		if (macro & WFS_CDM_RA_STACKER)						_str.append("WFS_CDM_RA_STACKER ");									
		if (macro & WFS_CDM_RA_REJECT)						_str.append("WFS_CDM_RA_REJECT ");									
		if (macro & WFS_CDM_RA_NOTSUPP)						_str.append("WFS_CDM_RA_NOTSUPP ");									
		return _str;																											
	}																															
																																
	/* values of WFSCDMCAPS.fwRetractTransportActions */																		
	/* values of WFSCDMCAPS.fwRetractStackerActions */																			
	static std::string get_cdm_fwRetractTransportActions(DWORD macro)															
	{																															
		std::string _str{};																										
		if (macro & WFS_CDM_PRESENT)						_str.append("WFS_CDM_PRESENT ");									
		if (macro & WFS_CDM_RETRACT)						_str.append("WFS_CDM_RETRACT ");									
		if (macro & WFS_CDM_REJECT)							_str.append("WFS_CDM_REJECT ");										
		if (macro & WFS_CDM_NOTSUPP)						_str.append("WFS_CDM_NOTSUPP ");									
		return _str;																											
	}																															
																																
	/* values of WFSCDMCAPS.fwMoveItems */																						
	static std::string get_cdm_fwMoveItems(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_CDM_FROMCU)							_str.append("WFS_CDM_FROMCU ");										
		if (macro & WFS_CDM_TOCU)							_str.append("WFS_CDM_TOCU ");										
		if (macro & WFS_CDM_TOTRANSPORT)					_str.append("WFS_CDM_TOTRANSPORT ");								
		return _str;																											
	}

	/* values of WFSCDMCASHUNIT.usType */																						
	static std::string get_cdm_usType_gui(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_TYPENA									: _str.assign("NA");												break;
		case WFS_CDM_TYPEREJECTCASSETTE						: _str.assign("REJ");												break;
		case WFS_CDM_TYPEBILLCASSETTE						: _str.assign("BIL");												break;
		case WFS_CDM_TYPECOINCYLINDER						: _str.assign("COINCYLINDER");										break;
		case WFS_CDM_TYPECOINDISPENSER						: _str.assign("COINDISPENSER");										break;
		case WFS_CDM_TYPERETRACTCASSETTE					: _str.assign("RET");												break;
		case WFS_CDM_TYPECOUPON								: _str.assign("COUPON");											break;
		case WFS_CDM_TYPEDOCUMENT							: _str.assign("DOCUMENT");											break;
		case WFS_CDM_TYPEREPCONTAINER						: _str.assign("REPCONTAINER");										break;
		case WFS_CDM_TYPERECYCLING							: _str.assign("REC");												break;
		default												: _str.assign("Unknown usType");									break;	
		}																														
		return _str;																											
	}

	/* values of WFSCDMCASHUNIT.usType */																						
	static std::string get_cdm_usType(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_TYPENA									: _str.assign("WFS_CDM_TYPENA");									break;
		case WFS_CDM_TYPEREJECTCASSETTE						: _str.assign("WFS_CDM_TYPEREJECTCASSETTE");						break;
		case WFS_CDM_TYPEBILLCASSETTE						: _str.assign("WFS_CDM_TYPEBILLCASSETTE");							break;
		case WFS_CDM_TYPECOINCYLINDER						: _str.assign("WFS_CDM_TYPECOINCYLINDER");							break;
		case WFS_CDM_TYPECOINDISPENSER						: _str.assign("WFS_CDM_TYPECOINDISPENSER");							break;
		case WFS_CDM_TYPERETRACTCASSETTE					: _str.assign("WFS_CDM_TYPERETRACTCASSETTE");						break;
		case WFS_CDM_TYPECOUPON								: _str.assign("WFS_CDM_TYPECOUPON");								break;
		case WFS_CDM_TYPEDOCUMENT							: _str.assign("WFS_CDM_TYPEDOCUMENT");								break;
		case WFS_CDM_TYPEREPCONTAINER						: _str.assign("WFS_CDM_TYPEREPCONTAINER");							break;
		case WFS_CDM_TYPERECYCLING							: _str.assign("WFS_CDM_TYPERECYCLING");								break;
		default												: _str.assign("Unknown usType");									break;	
		}																														
		return _str;																											
	}
																																
	/* values of WFSCDMCASHUNIT.usStatus */																						
	static std::string get_cdm_usStatus_gui(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_STATCUOK								: _str.assign("CUOK");												break;
		case WFS_CDM_STATCUFULL								: _str.assign("CUFULL");											break;
		case WFS_CDM_STATCUHIGH								: _str.assign("CUHIGH");											break;
		case WFS_CDM_STATCULOW								: _str.assign("CULOW");												break;
		case WFS_CDM_STATCUEMPTY							: _str.assign("CUEMPTY");											break;
		case WFS_CDM_STATCUINOP								: _str.assign("CUINOP");											break;
		case WFS_CDM_STATCUMISSING							: _str.assign("CUMISSING");											break;
		case WFS_CDM_STATCUNOVAL							: _str.assign("CUNOVAL");											break;
		case WFS_CDM_STATCUNOREF							: _str.assign("CUNOREF");											break;
		case WFS_CDM_STATCUMANIP							: _str.assign("CUMANIP");											break;
		default												: _str.assign("Unknown usStatus");									break;
		}																														
		return _str;																											
	}

	/* values of WFSCDMCASHUNIT.usStatus */																						
	static std::string get_cdm_usStatus(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_STATCUOK								: _str.assign("WFS_CDM_STATCUOK");									break;
		case WFS_CDM_STATCUFULL								: _str.assign("WFS_CDM_STATCUFULL");								break;
		case WFS_CDM_STATCUHIGH								: _str.assign("WFS_CDM_STATCUHIGH");								break;
		case WFS_CDM_STATCULOW								: _str.assign("WFS_CDM_STATCULOW");									break;
		case WFS_CDM_STATCUEMPTY							: _str.assign("WFS_CDM_STATCUEMPTY");								break;
		case WFS_CDM_STATCUINOP								: _str.assign("WFS_CDM_STATCUINOP");								break;
		case WFS_CDM_STATCUMISSING							: _str.assign("WFS_CDM_STATCUMISSING");								break;
		case WFS_CDM_STATCUNOVAL							: _str.assign("WFS_CDM_STATCUNOVAL");								break;
		case WFS_CDM_STATCUNOREF							: _str.assign("WFS_CDM_STATCUNOREF");								break;
		case WFS_CDM_STATCUMANIP							: _str.assign("WFS_CDM_STATCUMANIP");								break;
		default												: _str.assign("Unknown usStatus");									break;
		}																														
		return _str;																											
	}																																											
																																
	/* values of WFSCDMMIXTYPE.usMixType */																						
	static std::string get_cdm_usMixType(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_MIXALGORITHM							: _str.assign("WFS_CDM_MIXALGORITHM");								break;
		case WFS_CDM_MIXTABLE								: _str.assign("WFS_CDM_MIXTABLE");									break;
		default												: _str.assign("Unknown usMixType");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMMIXTYPE.usMixNumber */																					
	static std::string get_cdm_usMixNumber(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_INDIVIDUAL								: _str.assign("WFS_CDM_INDIVIDUAL");								break;
		default												: _str.assign("Unknown usMixNumber");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMMIXTYPE.usSubType (predefined mix algorithms) */															
	static std::string get_cdm_usSubType(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_MIX_MINIMUM_NUMBER_OF_BILLS			: _str.assign("WFS_CDM_MIX_MINIMUM_NUMBER_OF_BILLS");				break;
		case WFS_CDM_MIX_EQUAL_EMPTYING_OF_CASH_UNITS		: _str.assign("WFS_CDM_MIX_EQUAL_EMPTYING_OF_CASH_UNITS");			break;
		case WFS_CDM_MIX_MAXIMUM_NUMBER_OF_CASH_UNITS		: _str.assign("WFS_CDM_MIX_MAXIMUM_NUMBER_OF_CASH_UNITS");			break;
		default												: _str.assign("Unknown usSubType");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMPRESENTSTATUS.wPresentState */																			
	static std::string get_cdm_wPresentState(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_PRESENTED								: _str.assign("WFS_CDM_PRESENTED");									break;
		case WFS_CDM_NOTPRESENTED							: _str.assign("WFS_CDM_NOTPRESENTED");								break;
		case WFS_CDM_UNKNOWN								: _str.assign("WFS_CDM_UNKNOWN");									break;
		default												: _str.assign("Unknown wPresentState");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMDISPENSE.fwPosition */																					
	/* values of WFSCDMCAPS.fwPositions */																						
	/* values of WFSCDMOUTPOS.fwPosition */																						
	/* values of WFSCDMTELLERPOS.fwPosition */																					
	/* values of WFSCDMTELLERDETAILS.fwOutputPosition */																		
	/* values of WFSCDMPHYSICALCU.fwPosition */																					
	static std::string get_cdm_fwPosition(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_CDM_POSNULL)						_str.append("WFS_CDM_POSNULL ");									
		if (macro & WFS_CDM_POSLEFT)						_str.append("WFS_CDM_POSLEFT ");									
		if (macro & WFS_CDM_POSRIGHT)						_str.append("WFS_CDM_POSRIGHT ");									
		if (macro & WFS_CDM_POSCENTER)						_str.append("WFS_CDM_POSCENTER ");									
		if (macro & WFS_CDM_POSTOP)							_str.append("WFS_CDM_POSTOP ");										
		if (macro & WFS_CDM_POSBOTTOM)						_str.append("WFS_CDM_POSBOTTOM ");									
		if (macro & WFS_CDM_POSREJECT)						_str.append("WFS_CDM_POSREJECT ");									
		if (macro & WFS_CDM_POSFRONT)						_str.append("WFS_CDM_POSFRONT ");									
		if (macro & WFS_CDM_POSREAR)						_str.append("WFS_CDM_POSREAR ");									
		return _str;																											
	}																															
																																
	/* values of WFSCDMTELLERDETAILS.ulInputPosition */																			
	static std::string get_cdm_ulInputPosition(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_CDM_POSINLEFT)						_str.append("WFS_CDM_POSINLEFT ");									
		if (macro & WFS_CDM_POSINRIGHT)						_str.append("WFS_CDM_POSINRIGHT ");									
		if (macro & WFS_CDM_POSINCENTER)					_str.append("WFS_CDM_POSINCENTER ");								
		if (macro & WFS_CDM_POSINTOP)						_str.append("WFS_CDM_POSINTOP ");									
		if (macro & WFS_CDM_POSINBOTTOM)					_str.append("WFS_CDM_POSINBOTTOM ");								
		if (macro & WFS_CDM_POSINFRONT)						_str.append("WFS_CDM_POSINFRONT ");									
		if (macro & WFS_CDM_POSINREAR)						_str.append("WFS_CDM_POSINREAR ");									
		return _str;																											
	}																															
																																
	/* values of fwExchangeType */																								
	static std::string get_cdm_fwExchangeType(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_CDM_EXBYHAND)						_str.append("WFS_CDM_EXBYHAND ");									
		if (macro & WFS_CDM_EXTOCASSETTES)					_str.append("WFS_CDM_EXTOCASSETTES ");								
		return _str;																											
	}																															
																																
	/* values of WFSCDMTELLERUPDATE.usAction */																					
	static std::string get_cdm_usAction(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_CREATE_TELLER							: _str.assign("WFS_CDM_CREATE_TELLER");								break;
		case WFS_CDM_MODIFY_TELLER							: _str.assign("WFS_CDM_MODIFY_TELLER");								break;
		case WFS_CDM_DELETE_TELLER							: _str.assign("WFS_CDM_DELETE_TELLER");								break;
		default												: _str.assign("Unknown usAction");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCDMCUERROR.wFailure */																						
	static std::string get_cdm_wFailure(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_CASHUNITEMPTY							: _str.assign("WFS_CDM_CASHUNITEMPTY");								break;
		case WFS_CDM_CASHUNITERROR							: _str.assign("WFS_CDM_CASHUNITERROR");								break;
		case WFS_CDM_CASHUNITFULL							: _str.assign("WFS_CDM_CASHUNITFULL");								break;
		case WFS_CDM_CASHUNITLOCKED							: _str.assign("WFS_CDM_CASHUNITLOCKED");							break;
		case WFS_CDM_CASHUNITINVALID						: _str.assign("WFS_CDM_CASHUNITINVALID");							break;
		case WFS_CDM_CASHUNITCONFIG							: _str.assign("WFS_CDM_CASHUNITCONFIG");							break;
		default												: _str.assign("Unknown wFailure");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of lpusReason in WFS_EXEE_CDM_NOTESERROR */																		
	static std::string get_cdm_usReason(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CDM_DOUBLENOTEDETECTED						: _str.assign("WFS_CDM_DOUBLENOTEDETECTED");						break;
		case WFS_CDM_LONGNOTEDETECTED						: _str.assign("WFS_CDM_LONGNOTEDETECTED");							break;
		case WFS_CDM_SKEWEDNOTE								: _str.assign("WFS_CDM_SKEWEDNOTE");								break;
		case WFS_CDM_INCORRECTCOUNT							: _str.assign("WFS_CDM_INCORRECTCOUNT");							break;
		case WFS_CDM_NOTESTOOCLOSE							: _str.assign("WFS_CDM_NOTESTOOCLOSE");								break;
		default												: _str.assign("Unknown NOTESERROR");								break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS CDM Macros */																										
	/*=================================================================*/														
																																
	/* values of WFSPINSTATUS.fwDevice */																						
	static std::string get_pin_fwDevice(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_DEVONLINE							: _str.assign("WFS_PIN_DEVONLINE");									break;
			case WFS_PIN_DEVOFFLINE							: _str.assign("WFS_PIN_DEVOFFLINE");								break;
			case WFS_PIN_DEVPOWEROFF						: _str.assign("WFS_PIN_DEVPOWEROFF");								break;
			case WFS_PIN_DEVNODEVICE						: _str.assign("WFS_PIN_DEVNODEVICE");								break;
			case WFS_PIN_DEVHWERROR							: _str.assign("WFS_PIN_DEVHWERROR");								break;
			case WFS_PIN_DEVUSERERROR						: _str.assign("WFS_PIN_DEVUSERERROR");								break;
			case WFS_PIN_DEVBUSY							: _str.assign("WFS_PIN_DEVBUSY");									break;		
			default											: _str.assign("Unknown fwStatus");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINSTATUS.fwEncStat */																						
	static std::string get_pin_fwEncStat(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_ENCREADY							: _str.assign("WFS_PIN_ENCREADY");									break;
			case WFS_PIN_ENCNOTREADY						: _str.assign("WFS_PIN_ENCNOTREADY");								break;
			case WFS_PIN_ENCNOTINITIALIZED					: _str.assign("WFS_PIN_ENCNOTINITIALIZED");							break;
			case WFS_PIN_ENCBUSY							: _str.assign("WFS_PIN_ENCBUSY");									break;
			case WFS_PIN_ENCUNDEFINED						: _str.assign("WFS_PIN_ENCUNDEFINED");								break;
			case WFS_PIN_ENCINITIALIZED						: _str.assign("WFS_PIN_ENCINITIALIZED");							break;
			default											: _str.assign("Unknown fwEncStat");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.wType */																							
	static std::string get_pin_wType(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_TYPEEPP)						_str.append("WFS_PIN_TYPEEPP ");									
		if (macro & WFS_PIN_TYPEEDM)						_str.append("WFS_PIN_TYPEEDM ");									
		if (macro & WFS_PIN_TYPEHSM)						_str.append("WFS_PIN_TYPEHSM ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwAlgorithms, WFSPINCRYPT.wAlgorithm */																
	static std::string get_pin_fwAlgorithms(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_CRYPTDESECB)					_str.append("WFS_PIN_CRYPTDESECB ");								
		if (macro & WFS_PIN_CRYPTDESCBC)					_str.append("WFS_PIN_CRYPTDESCBC ");								
		if (macro & WFS_PIN_CRYPTDESCFB)					_str.append("WFS_PIN_CRYPTDESCFB ");								
		if (macro & WFS_PIN_CRYPTRSA)						_str.append("WFS_PIN_CRYPTRSA ");									
		if (macro & WFS_PIN_CRYPTECMA)						_str.append("WFS_PIN_CRYPTECMA ");									
		if (macro & WFS_PIN_CRYPTDESMAC)					_str.append("WFS_PIN_CRYPTDESMAC ");								
		if (macro & WFS_PIN_CRYPTTRIDESECB)					_str.append("WFS_PIN_CRYPTTRIDESECB ");								
		if (macro & WFS_PIN_CRYPTTRIDESCBC)					_str.append("WFS_PIN_CRYPTTRIDESCBC ");								
		if (macro & WFS_PIN_CRYPTTRIDESCFB)					_str.append("WFS_PIN_CRYPTTRIDESCFB ");								
		if (macro & WFS_PIN_CRYPTTRIDESMAC)					_str.append("WFS_PIN_CRYPTTRIDESMAC ");								
		if (macro & WFS_PIN_CRYPTMAAMAC)					_str.append("WFS_PIN_CRYPTMAAMAC ");								
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwPinFormats */																						
	static std::string get_pin_fwPinFormats(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_FORM3624)						_str.append("WFS_PIN_FORM3624 ");									
		if (macro & WFS_PIN_FORMANSI)						_str.append("WFS_PIN_FORMANSI ");									
		if (macro & WFS_PIN_FORMISO0)						_str.append("WFS_PIN_FORMISO0 ");									
		if (macro & WFS_PIN_FORMISO1)						_str.append("WFS_PIN_FORMISO1 ");									
		if (macro & WFS_PIN_FORMECI2)						_str.append("WFS_PIN_FORMECI2 ");									
		if (macro & WFS_PIN_FORMECI3)						_str.append("WFS_PIN_FORMECI3 ");									
		if (macro & WFS_PIN_FORMVISA)						_str.append("WFS_PIN_FORMVISA ");									
		if (macro & WFS_PIN_FORMDIEBOLD)					_str.append("WFS_PIN_FORMDIEBOLD ");								
		if (macro & WFS_PIN_FORMDIEBOLDCO)					_str.append("WFS_PIN_FORMDIEBOLDCO ");								
		if (macro & WFS_PIN_FORMVISA3)						_str.append("WFS_PIN_FORMVISA3 ");									
		if (macro & WFS_PIN_FORMBANKSYS)					_str.append("WFS_PIN_FORMBANKSYS ");								
		if (macro & WFS_PIN_FORMEMV)						_str.append("WFS_PIN_FORMEMV ");									
		if (macro & WFS_PIN_FORMISO3)						_str.append("WFS_PIN_FORMISO3 ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwDerivationAlgorithms */																			
	static std::string get_pin_fwDerivationAlgorithms(DWORD macro)																
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_CHIP_ZKA)						_str.append("WFS_PIN_CHIP_ZKA ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwPresentationAlgorithms */																			
	static std::string get_pin_fwPresentationAlgorithms(DWORD macro)															
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_PRESENT_CLEAR)					_str.append("WFS_PIN_PRESENT_CLEAR ");								
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwDisplay */																						
	static std::string get_pin_fwDisplay(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_DISPNONE							: _str.assign("WFS_PIN_DISPNONE");									break;
			case WFS_PIN_DISPLEDTHROUGH						: _str.assign("WFS_PIN_DISPLEDTHROUGH");							break;
			case WFS_PIN_DISPDISPLAY						: _str.assign("WFS_PIN_DISPDISPLAY");								break;
			default											: _str.assign("Unknown fwDisplay");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwIDKey */																							
	static std::string get_pin_fwIDKey(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_IDKEYINITIALIZATION)			_str.append("WFS_PIN_IDKEYINITIALIZATION ");						
		if (macro & WFS_PIN_IDKEYIMPORT)					_str.append("WFS_PIN_IDKEYIMPORT ");								
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwValidationAlgorithms */																			
	static std::string get_pin_fwValidationAlgorithms(DWORD macro)																
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_DES)							_str.append("WFS_PIN_DES ");										
		if (macro & WFS_PIN_EUROCHEQUE)						_str.append("WFS_PIN_EUROCHEQUE ");									
		if (macro & WFS_PIN_VISA)							_str.append("WFS_PIN_VISA ");										
		if (macro & WFS_PIN_DES_OFFSET)						_str.append("WFS_PIN_DES_OFFSET ");									
		if (macro & WFS_PIN_BANKSYS)						_str.append("WFS_PIN_BANKSYS ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINCAPS.fwKeyCheckModes and																					
	WFSPINIMPORTKEYEX.wKeyCheckMode */																							
	static std::string get_pin_fwKeyCheckModes(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_KCVNONE)						_str.append("WFS_PIN_KCVNONE ");									
		if (macro & WFS_PIN_KCVSELF)						_str.append("WFS_PIN_KCVSELF ");									
		if (macro & WFS_PIN_KCVZERO)						_str.append("WFS_PIN_KCVZERO ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINKEYDETAIL.fwUse and values of WFSPINKEYDETAILEX.dwUse */													
	static std::string get_pin_fwUse(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_USECRYPT)						_str.append("WFS_PIN_USECRYPT ");									
		if (macro & WFS_PIN_USEFUNCTION)					_str.append("WFS_PIN_USEFUNCTION ");								
		if (macro & WFS_PIN_USEMACING)						_str.append("WFS_PIN_USEMACING ");									
		if (macro & WFS_PIN_USEKEYENCKEY)					_str.append("WFS_PIN_USEKEYENCKEY  ");								
		if (macro & WFS_PIN_USENODUPLICATE)					_str.append("WFS_PIN_USENODUPLICATE  ");							
		if (macro & WFS_PIN_USESVENCKEY)					_str.append("WFS_PIN_USESVENCKEY ");								
		if (macro & WFS_PIN_USECONSTRUCT)					_str.append("WFS_PIN_USECONSTRUCT ");								
		if (macro & WFS_PIN_USEPINLOCAL)					_str.append("WFS_PIN_USEPINLOCAL ");								
		if (macro & WFS_PIN_USERSAPUBLIC)					_str.append("WFS_PIN_USERSAPUBLIC  ");								
		if (macro & WFS_PIN_USERSAPRIVATE)					_str.append("WFS_PIN_USERSAPRIVATE  ");								
		if (macro & WFS_PIN_USECHIPINFO)					_str.append("WFS_PIN_USECHIPINFO  ");								
		if (macro & WFS_PIN_USECHIPPIN)						_str.append("WFS_PIN_USECHIPPIN ");									
		if (macro & WFS_PIN_USECHIPPS)						_str.append("WFS_PIN_USECHIPPS ");									
		if (macro & WFS_PIN_USECHIPMAC)						_str.append("WFS_PIN_USECHIPMAC ");									
		if (macro & WFS_PIN_USECHIPLT)						_str.append("WFS_PIN_USECHIPLT ");									
		if (macro & WFS_PIN_USECHIPMACLZ)					_str.append("WFS_PIN_USECHIPMACLZ ");								
		if (macro & WFS_PIN_USECHIPMACAZ)					_str.append("WFS_PIN_USECHIPMACAZ ");								
		if (macro & WFS_PIN_USERSAPUBLICVERIFY)				_str.append("WFS_PIN_USERSAPUBLICVERIFY ");							
		if (macro & WFS_PIN_USERSAPRIVATESIGN)				_str.append("WFS_PIN_USERSAPRIVATESIGN ");							
		return _str;																											
	}																															
																																
	/* values of WFSPINFUNCKEYDETAIL.ulFuncMask */																				
	static std::string get_pin_ulFuncMask(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_FK_0)							_str.append("WFS_PIN_FK_0 ");										
		if (macro & WFS_PIN_FK_1)							_str.append("WFS_PIN_FK_1 ");										
		if (macro & WFS_PIN_FK_2)							_str.append("WFS_PIN_FK_2 ");										
		if (macro & WFS_PIN_FK_3)							_str.append("WFS_PIN_FK_3 ");										
		if (macro & WFS_PIN_FK_4)							_str.append("WFS_PIN_FK_4 ");										
		if (macro & WFS_PIN_FK_5)							_str.append("WFS_PIN_FK_5 ");										
		if (macro & WFS_PIN_FK_6)							_str.append("WFS_PIN_FK_6 ");										
		if (macro & WFS_PIN_FK_7)							_str.append("WFS_PIN_FK_7 ");										
		if (macro & WFS_PIN_FK_8)							_str.append("WFS_PIN_FK_8 ");										
		if (macro & WFS_PIN_FK_9)							_str.append("WFS_PIN_FK_9 ");										
		if (macro & WFS_PIN_FK_ENTER)						_str.append("WFS_PIN_FK_ENTER ");									
		if (macro & WFS_PIN_FK_CANCEL)						_str.append("WFS_PIN_FK_CANCEL ");									
		if (macro & WFS_PIN_FK_CLEAR)						_str.append("WFS_PIN_FK_CLEAR ");									
		if (macro & WFS_PIN_FK_BACKSPACE)					_str.append("WFS_PIN_FK_BACKSPACE ");								
		if (macro & WFS_PIN_FK_HELP)						_str.append("WFS_PIN_FK_HELP ");									
		if (macro & WFS_PIN_FK_DECPOINT)					_str.append("WFS_PIN_FK_DECPOINT ");								
		if (macro & WFS_PIN_FK_00)							_str.append("WFS_PIN_FK_00 ");										
		if (macro & WFS_PIN_FK_000)							_str.append("WFS_PIN_FK_000 ");										
		if (macro & WFS_PIN_FK_RES1)						_str.append("WFS_PIN_FK_RES1 ");									
		if (macro & WFS_PIN_FK_RES2)						_str.append("WFS_PIN_FK_RES2 ");									
		if (macro & WFS_PIN_FK_RES3)						_str.append("WFS_PIN_FK_RES3 ");									
		if (macro & WFS_PIN_FK_RES4)						_str.append("WFS_PIN_FK_RES4 ");									
		if (macro & WFS_PIN_FK_RES5)						_str.append("WFS_PIN_FK_RES5 ");									
		if (macro & WFS_PIN_FK_RES6)						_str.append("WFS_PIN_FK_RES6 ");									
		if (macro & WFS_PIN_FK_RES7)						_str.append("WFS_PIN_FK_RES7 ");									
		if (macro & WFS_PIN_FK_RES8)						_str.append("WFS_PIN_FK_RES8 ");									
		if (macro & WFS_PIN_FK_OEM1)						_str.append("WFS_PIN_FK_OEM1 ");									
		if (macro & WFS_PIN_FK_OEM2)						_str.append("WFS_PIN_FK_OEM2 ");									
		if (macro & WFS_PIN_FK_OEM3)						_str.append("WFS_PIN_FK_OEM3 ");									
		if (macro & WFS_PIN_FK_OEM4)						_str.append("WFS_PIN_FK_OEM4 ");									
		if (macro & WFS_PIN_FK_OEM5)						_str.append("WFS_PIN_FK_OEM5 ");									
		if (macro & WFS_PIN_FK_OEM6)						_str.append("WFS_PIN_FK_OEM6 ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINFUNCKEY.ulFDK */																							
	static std::string get_pin_ulFDK(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_FK_FDK01)						_str.append("WFS_PIN_FK_FDK01 ");									
		if (macro & WFS_PIN_FK_FDK02)						_str.append("WFS_PIN_FK_FDK02 ");									
		if (macro & WFS_PIN_FK_FDK03)						_str.append("WFS_PIN_FK_FDK03 ");									
		if (macro & WFS_PIN_FK_FDK04)						_str.append("WFS_PIN_FK_FDK04 ");									
		if (macro & WFS_PIN_FK_FDK05)						_str.append("WFS_PIN_FK_FDK05 ");									
		if (macro & WFS_PIN_FK_FDK06)						_str.append("WFS_PIN_FK_FDK06 ");									
		if (macro & WFS_PIN_FK_FDK07)						_str.append("WFS_PIN_FK_FDK07 ");									
		if (macro & WFS_PIN_FK_FDK08)						_str.append("WFS_PIN_FK_FDK08 ");									
		if (macro & WFS_PIN_FK_FDK09)						_str.append("WFS_PIN_FK_FDK09 ");									
		if (macro & WFS_PIN_FK_FDK10)						_str.append("WFS_PIN_FK_FDK10 ");									
		if (macro & WFS_PIN_FK_FDK11)						_str.append("WFS_PIN_FK_FDK11 ");									
		if (macro & WFS_PIN_FK_FDK12)						_str.append("WFS_PIN_FK_FDK12 ");									
		if (macro & WFS_PIN_FK_FDK13)						_str.append("WFS_PIN_FK_FDK13 ");									
		if (macro & WFS_PIN_FK_FDK14)						_str.append("WFS_PIN_FK_FDK14 ");									
		if (macro & WFS_PIN_FK_FDK15)						_str.append("WFS_PIN_FK_FDK15 ");									
		if (macro & WFS_PIN_FK_FDK16)						_str.append("WFS_PIN_FK_FDK16 ");									
		if (macro & WFS_PIN_FK_FDK17)						_str.append("WFS_PIN_FK_FDK17 ");									
		if (macro & WFS_PIN_FK_FDK18)						_str.append("WFS_PIN_FK_FDK18 ");									
		if (macro & WFS_PIN_FK_FDK19)						_str.append("WFS_PIN_FK_FDK19 ");									
		if (macro & WFS_PIN_FK_FDK20)						_str.append("WFS_PIN_FK_FDK20 ");									
		if (macro & WFS_PIN_FK_FDK21)						_str.append("WFS_PIN_FK_FDK21 ");									
		if (macro & WFS_PIN_FK_FDK22)						_str.append("WFS_PIN_FK_FDK22 ");									
		if (macro & WFS_PIN_FK_FDK23)						_str.append("WFS_PIN_FK_FDK23 ");									
		if (macro & WFS_PIN_FK_FDK24)						_str.append("WFS_PIN_FK_FDK24 ");									
		if (macro & WFS_PIN_FK_FDK25)						_str.append("WFS_PIN_FK_FDK25 ");									
		if (macro & WFS_PIN_FK_FDK26)						_str.append("WFS_PIN_FK_FDK26 ");									
		if (macro & WFS_PIN_FK_FDK27)						_str.append("WFS_PIN_FK_FDK27 ");									
		if (macro & WFS_PIN_FK_FDK28)						_str.append("WFS_PIN_FK_FDK28 ");									
		if (macro & WFS_PIN_FK_FDK29)						_str.append("WFS_PIN_FK_FDK29 ");									
		if (macro & WFS_PIN_FK_FDK30)						_str.append("WFS_PIN_FK_FDK30 ");									
		if (macro & WFS_PIN_FK_FDK31)						_str.append("WFS_PIN_FK_FDK31 ");									
		if (macro & WFS_PIN_FK_FDK32)						_str.append("WFS_PIN_FK_FDK32 ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINCRYPT.wMode */																							
	static std::string get_pin_wMode(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_MODEENCRYPT						: _str.assign("WFS_PIN_MODEENCRYPT");								break;
			case WFS_PIN_MODEDECRYPT						: _str.assign("WFS_PIN_MODEDECRYPT");								break;
			case WFS_PIN_MODERANDOM							: _str.assign("WFS_PIN_MODERANDOM");								break;
			default											: _str.assign("Unknown wMode");										break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINENTRY.wCompletion */																						
	static std::string get_pin_wCompletion(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_COMPAUTO							: _str.assign("WFS_PIN_COMPAUTO");									break;
			case WFS_PIN_COMPENTER							: _str.assign("WFS_PIN_COMPENTER");									break;
			case WFS_PIN_COMPCANCEL							: _str.assign("WFS_PIN_COMPCANCEL");								break;
			case WFS_PIN_COMPCONTINUE						: _str.assign("WFS_PIN_COMPCONTINUE");								break;
			case WFS_PIN_COMPCLEAR							: _str.assign("WFS_PIN_COMPCLEAR");									break;
			case WFS_PIN_COMPBACKSPACE						: _str.assign("WFS_PIN_COMPBACKSPACE");								break;
			case WFS_PIN_COMPFDK							: _str.assign("WFS_PIN_COMPFDK");									break;
			case WFS_PIN_COMPHELP							: _str.assign("WFS_PIN_COMPHELP");									break;
			case WFS_PIN_COMPFK								: _str.assign("WFS_PIN_COMPFK");									break;
			case WFS_PIN_COMPCONTFDK						: _str.assign("WFS_PIN_COMPCONTFDK");								break;
			default											: _str.assign("Unknown wCompletion");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINSECMSG.wProtocol */																						
	static std::string get_pin_secmsg_wProtocol(DWORD macro)																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_PROTISOAS							: _str.assign("WFS_PIN_PROTISOAS");									break;
			case WFS_PIN_PROTISOLZ							: _str.assign("WFS_PIN_PROTISOLZ");									break;
			case WFS_PIN_PROTISOPS							: _str.assign("WFS_PIN_PROTISOPS");									break;
			case WFS_PIN_PROTCHIPZKA						: _str.assign("WFS_PIN_PROTCHIPZKA");								break;
			case WFS_PIN_PROTRAWDATA						: _str.assign("WFS_PIN_PROTRAWDATA");								break;
			case WFS_PIN_PROTPBM							: _str.assign("WFS_PIN_PROTPBM");									break;
			case WFS_PIN_PROTHSMLDI							: _str.assign("WFS_PIN_PROTHSMLDI");								break;
			default											: _str.assign("Unknown wProtocol");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINHSMINIT.wInitMode. */																					
	static std::string get_pin_wInitMode(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_INITTEMP							: _str.assign("WFS_PIN_INITTEMP");									break;
			case WFS_PIN_INITDEFINITE						: _str.assign("WFS_PIN_INITDEFINITE");								break;
			case WFS_PIN_INITIRREVERSIBLE					: _str.assign("WFS_PIN_INITIRREVERSIBLE");							break;
			default											: _str.assign("Unknown wInitMode");									break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINENCIO.wProtocol */																						
	static std::string get_pin_encio_wProtocol(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_ENC_PROT_CH)					_str.append("WFS_PIN_ENC_PROT_CH ");								
		if (macro & WFS_PIN_ENC_PROT_GIECB)					_str.append("WFS_PIN_ENC_PROT_GIECB ");								
		return _str;																											
	}																															
																																
	/* values for WFS_SRVE_PIN_CERTIFICATE_CHANGE */																			
	static std::string get_pin__WFS_SRVE_PIN_CERTIFICATE_CHANGE(DWORD macro)													
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_CERT_PRIMARY)					_str.append("WFS_PIN_CERT_PRIMARY ");								
		if (macro & WFS_PIN_CERT_SECONDARY)					_str.append("WFS_PIN_CERT_SECONDARY ");								
		if (macro & WFS_PIN_CERT_NOTREADY)					_str.append("WFS_PIN_CERT_NOTREADY ");								
		return _str;																											
	}																															
																																
	/* Values for WFSPINCAPS.dwRSAAuthenticationScheme and the fast-track Capabilities											
	lpszExtra parameter, REMOTE_KEY_SCHEME. */																					
	static std::string get_pin_dwRSAAuthenticationScheme(DWORD macro)															
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_RSA_AUTH_2PARTY_SIG)			_str.append("WFS_PIN_RSA_AUTH_2PARTY_SIG ");						
		if (macro & WFS_PIN_RSA_AUTH_3PARTY_CERT)			_str.append("WFS_PIN_RSA_AUTH_3PARTY_CERT ");						
		return _str;																											
	}																															
																																
	/* Values for WFSPINCAPS.dwSignatureScheme and the fast-track Capabilities lpzExtra											
	parameter, SIGNATURE_CAPABILITIES. */																						
	static std::string get_pin_dwSignatureScheme(DWORD macro)																	
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_SIG_GEN_RSA_KEY_PAIR)			_str.append("WFS_PIN_SIG_GEN_RSA_KEY_PAIR ");						
		if (macro & WFS_PIN_SIG_RANDOM_NUMBER)				_str.append("WFS_PIN_SIG_RANDOM_NUMBER ");							
		if (macro & WFS_PIN_SIG_EXPORT_EPP_ID)				_str.append("WFS_PIN_SIG_EXPORT_EPP_ID ");							
		return _str;																											
	}																															
																																
	/* values of WFSPINIMPORTRSAPUBLICKEY.dwRSASignatureAlgorithm */															
	static std::string get_pin_dwRSASignatureAlgorithm(DWORD macro)																
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_SIGN_NA)						_str.append("WFS_PIN_SIGN_NA ");									
		if (macro & WFS_PIN_SIGN_RSASSA_PKCS1_V1_5)			_str.append("WFS_PIN_SIGN_RSASSA_PKCS1_V1_5 ");						
		if (macro & WFS_PIN_SIGN_RSASSA_PSS)				_str.append("WFS_PIN_SIGN_RSASSA_PSS ");							
		return _str;																											
	}																															
																																
	/* values of WFSPINIMPORTRSAPUBLICKEYOUTPUT.dwRSAKeyCheckMode */															
	static std::string get_pin_dwRSAKeyCheckMode(DWORD macro)																	
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_RSA_KCV_NONE)					_str.append("WFS_PIN_RSA_KCV_NONE ");								
		if (macro & WFS_PIN_RSA_KCV_SHA1)					_str.append("WFS_PIN_RSA_KCV_SHA1 ");								
		return _str;																											
	}																															
																																
	/* values of WFSPINEXPORTRSAISSUERSIGNEDITEM.wExportItemType and */															
	/* WFSPINEXPORTRSAEPPSIGNEDITEM.wExportItemType */																			
	static std::string get_pin_wExportItemType(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_EXPORT_EPP_ID)					_str.append("WFS_PIN_EXPORT_EPP_ID ");								
		if (macro & WFS_PIN_EXPORT_PUBLIC_KEY)				_str.append("WFS_PIN_EXPORT_PUBLIC_KEY ");							
		return _str;																											
	}																															
																																
	/* values of WFSPINIMPORTRSASIGNEDDESKEY.dwRSAEncipherAlgorithm */															
	static std::string get_pin_dwRSAEncipherAlgorithm(DWORD macro)																
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_CRYPT_RSAES_PKCS1_V1_5)			_str.append("WFS_PIN_CRYPT_RSAES_PKCS1_V1_5 ");						
		if (macro & WFS_PIN_CRYPT_RSAES_OAEP)				_str.append("WFS_PIN_CRYPT_RSAES_OAEP ");							
		return _str;																											
	}																															
																																
	/* values of WFSPINGENERATERSAKEYPAIR.wExponentValue */																		
	static std::string get_pin_wExponentValue(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_DEFAULT							: _str.assign("WFS_PIN_DEFAULT");									break;
			case WFS_PIN_EXPONENT_1							: _str.assign("WFS_PIN_EXPONENT_1");								break;
			case WFS_PIN_EXPONENT_4							: _str.assign("WFS_PIN_EXPONENT_4");								break;
			case WFS_PIN_EXPONENT_16						: _str.assign("WFS_PIN_EXPONENT_16");								break;
			default											: _str.assign("Unknown wExponentValue");							break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSPINIMPORTRSASIGNEDDESKEYOUTPUT.wKeyLength and */															
	/* WFSPINIMPORTRSAENCIPHEREDPKCS7KEYOUTPUT.wKeyLength */																	
	static std::string get_pin_wKeyLength(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_KEYSINGLE)						_str.append("WFS_PIN_KEYSINGLE ");									
		if (macro & WFS_PIN_KEYDOUBLE)						_str.append("WFS_PIN_KEYDOUBLE ");									
		return _str;																											
	}																															
																																
	/* values of WFSPINGETCERTIFICATE.wGetCertificate */																		
	static std::string get_pin_wGetCertificate(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
			case WFS_PIN_PUBLICENCKEY						: _str.assign("WFS_PIN_PUBLICENCKEY");								break;
			case WFS_PIN_PUBLICVERIFICATIONKEY				: _str.assign("WFS_PIN_PUBLICVERIFICATIONKEY");						break;
			default											: _str.assign("Unknown wGetCertificate");							break;
		}																														
		return _str;																											
	}																															
																																
	/* values for WFSPINEMVIMPORTPUBLICKEY.wImportScheme */																		
	static std::string get_pin_wImportScheme(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_EMV_IMPORT_PLAIN_CA)			_str.append("WFS_PIN_EMV_IMPORT_PLAIN_CA ");						
		if (macro & WFS_PIN_EMV_IMPORT_CHKSUM_CA)			_str.append("WFS_PIN_EMV_IMPORT_CHKSUM_CA ");						
		if (macro & WFS_PIN_EMV_IMPORT_EPI_CA)				_str.append("WFS_PIN_EMV_IMPORT_EPI_CA ");							
		if (macro & WFS_PIN_EMV_IMPORT_ISSUER)				_str.append("WFS_PIN_EMV_IMPORT_ISSUER ");							
		if (macro & WFS_PIN_EMV_IMPORT_ICC)					_str.append("WFS_PIN_EMV_IMPORT_ICC ");								
		if (macro & WFS_PIN_EMV_IMPORT_ICC_PIN)				_str.append("WFS_PIN_EMV_IMPORT_ICC_PIN ");							
		if (macro & WFS_PIN_EMV_IMPORT_PKCSV1_5_CA)			_str.append("WFS_PIN_EMV_IMPORT_PKCSV1_5_CA ");						
		return _str;																											
	}																															
																																
	/* values for WFSPINDIGEST.wHashAlgorithm */																				
	static std::string get_pin_wHashAlgorithm(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_PIN_HASH_SHA1_DIGEST)				_str.append("WFS_PIN_HASH_SHA1_DIGEST ");							
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS TTU Macros */																										
	/*=================================================================*/														
																																
	/* Values of WFSTTUSTATUS.fwDevice */																						
	static std::string get_ttu_fwDevice(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_DEVONLINE								: _str.assign("WFS_TTU_DEVONLINE");									break;
		case WFS_TTU_DEVOFFLINE								: _str.assign("WFS_TTU_DEVOFFLINE");								break;
		case WFS_TTU_DEVPOWEROFF							: _str.assign("WFS_TTU_DEVPOWEROFF");								break;
		case WFS_TTU_DEVBUSY								: _str.assign("WFS_TTU_DEVBUSY");									break;
		case WFS_TTU_DEVNODEVICE							: _str.assign("WFS_TTU_DEVNODEVICE");								break;
		case WFS_TTU_DEVHWERROR								: _str.assign("WFS_TTU_DEVHWERROR");								break;
		case WFS_TTU_DEVUSERERROR							: _str.assign("WFS_TTU_DEVUSERERROR");								break;
		default												: _str.assign("Unknown fwDevice");									break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSTTUSTATUS.wKeyboard */																						
	static std::string get_ttu_wKeyboard(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_KBDNA									: _str.assign("WFS_TTU_KBDNA");										break;
		case WFS_TTU_KBDON									: _str.assign("WFS_TTU_KBDON");										break;
		case WFS_TTU_KBDOFF									: _str.assign("WFS_TTU_KBDOFF");									break;
		default												: _str.assign("Unknown wKeyboard");									break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSTTUSTATUS.wKeyLock */																						
	static std::string get_ttu_wKeyLock(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_KBDLOCKNA								: _str.assign("WFS_TTU_KBDLOCKNA");									break;
		case WFS_TTU_KBDLOCKON								: _str.assign("WFS_TTU_KBDLOCKON");									break;
		case WFS_TTU_KBDLOCKOFF								: _str.assign("WFS_TTU_KBDLOCKOFF");								break;
		case WFS_TTU_LEDS_MAX								: _str.assign("WFS_TTU_LEDS_MAX");									break;
		default												: _str.assign("Unknown wKeyLock");									break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSTTUSTATUS.fwLEDs */																							
	static std::string get_ttu_fwLEDs(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_TTU_LEDNA)							_str.append("WFS_TTU_LEDNA ");										
		if (macro & WFS_TTU_LEDOFF)							_str.append("WFS_TTU_LEDOFF ");										
		if (macro & WFS_TTU_LEDSLOWFLASH)					_str.append("WFS_TTU_LEDSLOWFLASH ");								
		if (macro & WFS_TTU_LEDMEDIUMFLASH)					_str.append("WFS_TTU_LEDMEDIUMFLASH ");								
		if (macro & WFS_TTU_LEDQUICKFLASH)					_str.append("WFS_TTU_LEDQUICKFLASH ");								
		if (macro & WFS_TTU_LEDCONTINUOUS)					_str.append("WFS_TTU_LEDCONTINUOUS ");								
		return _str;																											
	}																															
																																
	/* Values of WFSTTUCAPS.fwType */																							
	static std::string get_ttu_caps_fwType(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_TTU_FIXED)							_str.append("WFS_TTU_FIXED ");										
		if (macro & WFS_TTU_REMOVABLE)						_str.append("WFS_TTU_REMOVABLE ");									
		return _str;																											
	}																															
																																
	/* Values of WFSTTUCAPS.fwCharSupport, WFSTTUWRITE.fwCharSupport */															
	static std::string get_ttu_fwCharSupport(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_TTU_ASCII)							_str.append("WFS_TTU_ASCII ");										
		if (macro & WFS_TTU_UNICODE)						_str.append("WFS_TTU_UNICODE ");									
		return _str;																											
	}																															
																																
	/* Values of WFSTTUFRMFIELD.fwType */																						
	static std::string get_ttu_frmfield_fwType(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_FIELDTEXT								: _str.assign("WFS_TTU_FIELDTEXT");									break;
		case WFS_TTU_FIELDINVISIBLE							: _str.assign("WFS_TTU_FIELDINVISIBLE");							break;
		case WFS_TTU_FIELDPASSWORD							: _str.assign("WFS_TTU_FIELDPASSWORD");								break;
		default												: _str.assign("Unknown fwType");									break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSTTUFRMFIELD.fwClass */																						
	static std::string get_ttu_fwClass(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_CLASSOPTIONAL							: _str.assign("WFS_TTU_CLASSOPTIONAL");								break;
		case WFS_TTU_CLASSSTATIC							: _str.assign("WFS_TTU_CLASSSTATIC");								break;
		case WFS_TTU_CLASSREQUIRED							: _str.assign("WFS_TTU_CLASSREQUIRED");								break;
		default												: _str.assign("Unknown fwClass");									break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSTTUFRMFIELD.fwAccess */																						
	static std::string get_ttu_fwAccess(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_TTU_ACCESSREAD)						_str.append("WFS_TTU_ACCESSREAD ");									
		if (macro & WFS_TTU_ACCESSWRITE)					_str.append("WFS_TTU_ACCESSWRITE ");								
		return _str;																											
	}																															
																																
	/* Values of WFSTTUFRMFIELD.fwOverflow */																					
	static std::string get_ttu_fwOverflow(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_OVFTERMINATE							: _str.assign("WFS_TTU_OVFTERMINATE");								break;
		case WFS_TTU_OVFTRUNCATE							: _str.assign("WFS_TTU_OVFTRUNCATE");								break;
		case WFS_TTU_OVFOVERWRITE							: _str.assign("WFS_TTU_OVFOVERWRITE");								break;
		default												: _str.assign("Unknown fwOverflow");								break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSTTUWRITE.fwMode */																							
	static std::string get_ttu_fwMode(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_POSRELATIVE							: _str.assign("WFS_TTU_POSRELATIVE");								break;
		case WFS_TTU_POSABSOLUTE							: _str.assign("WFS_TTU_POSABSOLUTE");								break;
		default												: _str.assign("Unknown fwMode");									break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSTTUWRITE.fwTextAttr */																						
	static std::string get_ttu_fwTextAttr(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_TTU_TEXTUNDERLINE)					_str.append("WFS_TTU_TEXTUNDERLINE ");								
		if (macro & WFS_TTU_TEXTINVERTED)					_str.append("WFS_TTU_TEXTINVERTED ");								
		if (macro & WFS_TTU_TEXTFLASH)						_str.append("WFS_TTU_TEXTFLASH ");									
		return _str;																											
	}																															
																																
	/* Values of WFSTTUFRMREAD.fwEchoMode */																					
	static std::string get_ttu_fwEchoMode(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_ECHOTEXT								: _str.assign("WFS_TTU_ECHOTEXT");									break;
		case WFS_TTU_ECHOINVISIBLE							: _str.assign("WFS_TTU_ECHOINVISIBLE");								break;
		case WFS_TTU_ECHOPASSWORD							: _str.assign("WFS_TTU_ECHOPASSWORD");								break;
		default												: _str.assign("Unknown fwEchoMode");								break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of fwBeep */																										
	static std::string get_ttu_fwBeep(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_TTU_BEEPOFF)						_str.append("WFS_TTU_BEEPOFF ");									
		if (macro & WFS_TTU_BEEPKEYPRESS)					_str.append("WFS_TTU_BEEPKEYPRESS ");								
		if (macro & WFS_TTU_BEEPEXCLAMATION)				_str.append("WFS_TTU_BEEPEXCLAMATION ");							
		if (macro & WFS_TTU_BEEPWARNING)					_str.append("WFS_TTU_BEEPWARNING ");								
		if (macro & WFS_TTU_BEEPERROR)						_str.append("WFS_TTU_BEEPERROR ");									
		if (macro & WFS_TTU_BEEPCRITICAL)					_str.append("WFS_TTU_BEEPCRITICAL ");								
		if (macro & WFS_TTU_BEEPCONTINUOUS)					_str.append("WFS_TTU_BEEPCONTINUOUS ");								
		return _str;																											
	}																															
																																
	/* values of WFSTTUFIELDFAIL.wFailure */																					
	static std::string get_ttu_wFailure(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_FIELDREQUIRED								: _str.assign("WFS_TTU_FIELDREQUIRED");							break;
		case WFS_TTU_FIELDSTATICOVWR							: _str.assign("WFS_TTU_FIELDSTATICOVWR");						break;
		case WFS_TTU_FIELDOVERFLOW								: _str.assign("WFS_TTU_FIELDOVERFLOW");							break;
		case WFS_TTU_FIELDNOTFOUND								: _str.assign("WFS_TTU_FIELDNOTFOUND");							break;
		case WFS_TTU_FIELDNOTREAD								: _str.assign("WFS_TTU_FIELDNOTREAD");							break;
		case WFS_TTU_FIELDNOTWRITE								: _str.assign("WFS_TTU_FIELDNOTWRITE");							break;
		case WFS_TTU_FIELDTYPENOTSUPPORTED						: _str.assign("WFS_TTU_FIELDTYPENOTSUPPORTED");					break;
		case WFS_TTU_CHARSETFORM								: _str.assign("WFS_TTU_CHARSETFORM");							break;
		default													: _str.assign("Unknown wFailure");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSTTUKEYDETAIL.lpwCommandKeys */																				
	static std::string get_ttu_lpwCommandKeys(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_TTU_NOKEY										: _str.assign("WFS_TTU_NOKEY");									break;
		case WFS_TTU_CK_ENTER									: _str.assign("WFS_TTU_CK_ENTER");								break;
		case WFS_TTU_CK_CANCEL									: _str.assign("WFS_TTU_CK_CANCEL");								break;
		case WFS_TTU_CK_CLEAR									: _str.assign("WFS_TTU_CK_CLEAR");								break;
		case WFS_TTU_CK_BACKSPACE								: _str.assign("WFS_TTU_CK_BACKSPACE");							break;
		case WFS_TTU_CK_HELP									: _str.assign("WFS_TTU_CK_HELP");								break;
		case WFS_TTU_CK_00										: _str.assign("WFS_TTU_CK_00");									break;
		case WFS_TTU_CK_000										: _str.assign("WFS_TTU_CK_000");								break;
		case WFS_TTU_CK_ARROWUP									: _str.assign("WFS_TTU_CK_ARROWUP");							break;
		case WFS_TTU_CK_ARROWDOWN								: _str.assign("WFS_TTU_CK_ARROWDOWN");							break;
		case WFS_TTU_CK_ARROWLEFT								: _str.assign("WFS_TTU_CK_ARROWLEFT");							break;
		case WFS_TTU_CK_ARROWRIGHT								: _str.assign("WFS_TTU_CK_ARROWRIGHT");							break;
		case WFS_TTU_CK_OEM1									: _str.assign("WFS_TTU_CK_OEM1");								break;
		case WFS_TTU_CK_OEM2									: _str.assign("WFS_TTU_CK_OEM2");								break;
		case WFS_TTU_CK_OEM3									: _str.assign("WFS_TTU_CK_OEM3");								break;
		case WFS_TTU_CK_OEM4									: _str.assign("WFS_TTU_CK_OEM4");								break;
		case WFS_TTU_CK_OEM5									: _str.assign("WFS_TTU_CK_OEM5");								break;
		case WFS_TTU_CK_OEM6									: _str.assign("WFS_TTU_CK_OEM6");								break;
		case WFS_TTU_CK_OEM7									: _str.assign("WFS_TTU_CK_OEM7");								break;
		case WFS_TTU_CK_OEM8									: _str.assign("WFS_TTU_CK_OEM8");								break;
		case WFS_TTU_CK_OEM9									: _str.assign("WFS_TTU_CK_OEM9");								break;
		case WFS_TTU_CK_OEM10									: _str.assign("WFS_TTU_CK_OEM10");								break;
		case WFS_TTU_CK_OEM11									: _str.assign("WFS_TTU_CK_OEM11");								break;
		case WFS_TTU_CK_OEM12									: _str.assign("WFS_TTU_CK_OEM12");								break;
		case WFS_TTU_CK_FDK01									: _str.assign("WFS_TTU_CK_FDK01");								break;
		case WFS_TTU_CK_FDK02									: _str.assign("WFS_TTU_CK_FDK02");								break;
		case WFS_TTU_CK_FDK03									: _str.assign("WFS_TTU_CK_FDK03");								break;
		case WFS_TTU_CK_FDK04									: _str.assign("WFS_TTU_CK_FDK04");								break;
		case WFS_TTU_CK_FDK05									: _str.assign("WFS_TTU_CK_FDK05");								break;
		case WFS_TTU_CK_FDK06									: _str.assign("WFS_TTU_CK_FDK06");								break;
		case WFS_TTU_CK_FDK07									: _str.assign("WFS_TTU_CK_FDK07");								break;
		case WFS_TTU_CK_FDK08									: _str.assign("WFS_TTU_CK_FDK08");								break;
		case WFS_TTU_CK_FDK09									: _str.assign("WFS_TTU_CK_FDK09");								break;
		case WFS_TTU_CK_FDK10									: _str.assign("WFS_TTU_CK_FDK10");								break;
		case WFS_TTU_CK_FDK11									: _str.assign("WFS_TTU_CK_FDK11");								break;
		case WFS_TTU_CK_FDK12									: _str.assign("WFS_TTU_CK_FDK12");								break;
		case WFS_TTU_CK_FDK13									: _str.assign("WFS_TTU_CK_FDK13");								break;
		case WFS_TTU_CK_FDK14									: _str.assign("WFS_TTU_CK_FDK14");								break;
		case WFS_TTU_CK_FDK15									: _str.assign("WFS_TTU_CK_FDK15");								break;
		case WFS_TTU_CK_FDK16									: _str.assign("WFS_TTU_CK_FDK16");								break;
		case WFS_TTU_CK_FDK17									: _str.assign("WFS_TTU_CK_FDK17");								break;
		case WFS_TTU_CK_FDK18									: _str.assign("WFS_TTU_CK_FDK18");								break;
		case WFS_TTU_CK_FDK19									: _str.assign("WFS_TTU_CK_FDK19");								break;
		case WFS_TTU_CK_FDK20									: _str.assign("WFS_TTU_CK_FDK20");								break;
		case WFS_TTU_CK_FDK21									: _str.assign("WFS_TTU_CK_FDK21");								break;
		case WFS_TTU_CK_FDK22									: _str.assign("WFS_TTU_CK_FDK22");								break;
		case WFS_TTU_CK_FDK23									: _str.assign("WFS_TTU_CK_FDK23");								break;
		case WFS_TTU_CK_FDK24									: _str.assign("WFS_TTU_CK_FDK24");								break;
		case WFS_TTU_CK_FDK25									: _str.assign("WFS_TTU_CK_FDK25");								break;
		case WFS_TTU_CK_FDK26									: _str.assign("WFS_TTU_CK_FDK26");								break;
		case WFS_TTU_CK_FDK27									: _str.assign("WFS_TTU_CK_FDK27");								break;
		case WFS_TTU_CK_FDK28									: _str.assign("WFS_TTU_CK_FDK28");								break;
		case WFS_TTU_CK_FDK29									: _str.assign("WFS_TTU_CK_FDK29");								break;
		case WFS_TTU_CK_FDK30									: _str.assign("WFS_TTU_CK_FDK30");								break;
		case WFS_TTU_CK_FDK31									: _str.assign("WFS_TTU_CK_FDK31");								break;
		case WFS_TTU_CK_FDK32									: _str.assign("WFS_TTU_CK_FDK32");								break;
		default													: _str.assign("Unknown lpwCommandKeys");						break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS SIU Macros */																										
	/*=================================================================*/														
																																
	/* Values of WFSSIUSTATUS.fwDevice */																						
	static std::string get_siu_fwDevice(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_SIU_DEVONLINE									: _str.assign("WFS_SIU_DEVONLINE");								break;
		case WFS_SIU_DEVOFFLINE									: _str.assign("WFS_SIU_DEVOFFLINE");							break;
		case WFS_SIU_DEVPOWEROFF								: _str.assign("WFS_SIU_DEVPOWEROFF");							break;
		case WFS_SIU_DEVNODEVICE								: _str.assign("WFS_SIU_DEVNODEVICE");							break;
		case WFS_SIU_DEVHWERROR									: _str.assign("WFS_SIU_DEVHWERROR");							break;
		case WFS_SIU_DEVUSERERROR								: _str.assign("WFS_SIU_DEVUSERERROR");							break;
		case WFS_SIU_DEVBUSY									: _str.assign("WFS_SIU_DEVBUSY");								break;
		default													: _str.assign("Unknown fwDevice");								break;
		}																														
		return _str;																											
	}																															
																																
	/* Indices of WFSSIUSTATUS.fwSensors [...]																					
	WFSSIUCAPS.fwSensors [...]																									
	WFSSIUENABLE.fwSensors [...]																								
	WFSSIUPORTEVENT.wPortIndex																									
	WFSSIUPORTERROR.wPortIndex */																								
	static std::string get_siu_fwSensors(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_SIU_OPERATORSWITCH								: _str.assign("WFS_SIU_OPERATORSWITCH");						break;
		case WFS_SIU_TAMPER										: _str.assign("WFS_SIU_TAMPER");								break;
		case WFS_SIU_INTTAMPER									: _str.assign("WFS_SIU_INTTAMPER");								break;
		case WFS_SIU_SEISMIC									: _str.assign("WFS_SIU_SEISMIC");								break;
		case WFS_SIU_HEAT										: _str.assign("WFS_SIU_HEAT");									break;
		case WFS_SIU_PROXIMITY									: _str.assign("WFS_SIU_PROXIMITY");								break;
		case WFS_SIU_AMBLIGHT									: _str.assign("WFS_SIU_AMBLIGHT");								break;
		case WFS_SIU_ENHANCEDAUDIO								: _str.assign("WFS_SIU_ENHANCEDAUDIO");							break;
		default													: _str.assign("Unknown fwSensors");								break;
		}																														
		return _str;																											
	}																															
																																
	/* Indices of WFSSIUSTATUS.fwDoors [...]																					
	WFSSIUCAPS.fwDoors [...]																									
	WFSSIUENABLE.fwDoors [...]																									
	WFSSIUSETPORT.fwDoors [...]																									
	WFSSIUSETDOORS.wDoor																										
	WFSSIUPORTEVENT.wPortIndex																									
	WFSSIUPORTERROR.wPortIndex */																								
	static std::string get_siu_fwDoors(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_SIU_CABINET									: _str.assign("WFS_SIU_CABINET");								break;
		case WFS_SIU_SAFE										: _str.assign("WFS_SIU_SAFE");									break;
		case WFS_SIU_VANDALSHIELD								: _str.assign("WFS_SIU_VANDALSHIELD");							break;
		default													: _str.assign("Unknown fwDoors");								break;
		}																														
		return _str;																											
	}																															
																																
	/* Indices of WFSSIUSTATUS.fwIndicators [...]																				
	WFSSIUCAPS.fwIndicators [...]																								
	WFSSIUENABLE.fwIndicators [...]																								
	WFSSIUSETPORT.wIndicators [...]																								
	WFSSIUSETINDICATORS.wIndicator																								
	WFSSIUPORTEVENT.wPortIndex																									
	WFSSIUPORTERROR.wPortIndex */																								
	static std::string get_siu_fwIndicators(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_SIU_OPENCLOSE									: _str.assign("WFS_SIU_OPENCLOSE");								break;
		case WFS_SIU_FASCIALIGHT								: _str.assign("WFS_SIU_FASCIALIGHT");							break;
		case WFS_SIU_AUDIO										: _str.assign("WFS_SIU_AUDIO");									break;
		case WFS_SIU_HEATING									: _str.assign("WFS_SIU_HEATING");								break;
		default													: _str.assign("Unknown fwIndicators");							break;
		}																														
		return _str;																											
	}																															
																																
	/* Indices of WFSSIUSTATUS.fwAuxiliaries [...]																				
	WFSSIUCAPS.fwAuxiliaries [...]																								
	WFSSIUENABLE.fwAuxiliaries [...]																							
	WFSSIUSETPORT.wAuxiliaries [...]																							
	WFSSIUSETAUXILIARIES.wAuxiliary																								
	WFSSIUPORTEVENT.wPortIndex																									
	WFSSIUPORTERROR.wPortIndex */																								
	static std::string get_siu_fwAuxiliaries(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_SIU_VOLUME										: _str.assign("WFS_SIU_VOLUME");								break;
		case WFS_SIU_UPS										: _str.assign("WFS_SIU_UPS");									break;
		case WFS_SIU_REMOTE_STATUS_MONITOR						: _str.assign("WFS_SIU_REMOTE_STATUS_MONITOR");					break;
		case WFS_SIU_AUDIBLE_ALARM								: _str.assign("WFS_SIU_AUDIBLE_ALARM");							break;
		case WFS_SIU_ENHANCEDAUDIOCONTROL						: _str.assign("WFS_SIU_ENHANCEDAUDIOCONTROL");					break;
		default													: _str.assign("Unknown fwAuxiliaries");							break;
		}																														
		return _str;																											
	}																															
																																
	/* Indices of WFSSIUSTATUS.fwGuidLights [...]																				
	WFSSIUCAPS.fwGuidLights [...]																								
	WFSSIUENABLE.fwGuidLights [...]																								
	WFSSIUSETPORT.wGuidLights [...]																								
	WFSSIUSETGUIDLIGHTS.wGuidLight																								
	WFSSIUPORTEVENT.wPortIndex																									
	WFSSIUPORTERROR.wPortIndex */																								
	static std::string get_siu_fwGuidLights(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_SIU_CARDUNIT									: _str.assign("WFS_SIU_CARDUNIT");								break;
		case WFS_SIU_PINPAD										: _str.assign("WFS_SIU_PINPAD");								break;
		case WFS_SIU_NOTESDISPENSER								: _str.assign("WFS_SIU_NOTESDISPENSER");						break;
		case WFS_SIU_COINDISPENSER								: _str.assign("WFS_SIU_COINDISPENSER");							break;
		case WFS_SIU_RECEIPTPRINTER								: _str.assign("WFS_SIU_RECEIPTPRINTER");						break;
		case WFS_SIU_PASSBOOKPRINTER							: _str.assign("WFS_SIU_PASSBOOKPRINTER");						break;
		case WFS_SIU_ENVDEPOSITORY								: _str.assign("WFS_SIU_ENVDEPOSITORY");							break;
		case WFS_SIU_CHEQUEUNIT									: _str.assign("WFS_SIU_CHEQUEUNIT");							break;
		case WFS_SIU_BILLACCEPTOR								: _str.assign("WFS_SIU_BILLACCEPTOR");							break;
		case WFS_SIU_ENVDISPENSER								: _str.assign("WFS_SIU_ENVDISPENSER");							break;
		case WFS_SIU_DOCUMENTPRINTER							: _str.assign("WFS_SIU_DOCUMENTPRINTER");						break;
		case WFS_SIU_COINACCEPTOR								: _str.assign("WFS_SIU_COINACCEPTOR");							break;
		case WFS_SIU_SCANNER									: _str.assign("WFS_SIU_SCANNER");								break;
		default													: _str.assign("Unknown fwGuidLights");							break;
		}																														
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwSensors [...]																					
	WFSSIUSTATUS.fwDoors [...]																									
	WFSSIUSTATUS.fwIndicators [...]																								
	WFSSIUSTATUS.fwAuxiliaries [...]																							
	WFSSIUSTATUS.fwGuidLights [...]																								
	WFSSIUCAPS.fwSensors [...]																									
	WFSSIUCAPS.fwDoors [...]																									
	WFSSIUCAPS.fwIndicators [...]																								
	WFSSIUCAPS.fwAuxiliaries [...]																								
	WFSSIUCAPS.fwGuidLights [...] */																							
	static std::string get_siu__availability(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_AVAILABLE)							_str.append("WFS_SIU_AVAILABLE ");								
																																
		if (macro == WFS_SIU_NOT_AVAILABLE)						_str.assign("WFS_SIU_NOT_AVAILABLE ");							
																																
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwSensors [WFS_SIU_OPERATORSWITCH]																
	WFSSIUCAPS.fwSensors [WFS_SIU_OPERATORSWITCH]																				
	WFSSIUPORTEVENT.fwPortStatus																								
	WFSSIUPORTERROR.fwPortStatus */																								
	static std::string get_siu__operatorswitch(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_RUN)								_str.append("WFS_SIU_RUN ");									
		if (macro & WFS_SIU_MAINTENANCE)						_str.append("WFS_SIU_MAINTENANCE ");							
		if (macro & WFS_SIU_SUPERVISOR)							_str.append("WFS_SIU_SUPERVISOR ");								
																																
		if (macro == WFS_SIU_NOT_AVAILABLE)						_str.assign("WFS_SIU_NOT_AVAILABLE ");							
																																
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwDoors [...]																						
	WFSSIUSTATUS.fwIndicators [WFS_SIU_OPENCLOSE]																				
	WFSSIUCAPS.fwDoors [...]																									
	WFSSIUCAPS.fwIndicators [WFS_SIU_OPENCLOSE]																					
	WFSSIUSETPORT.fwDoors [...]																									
	WFSSIUSETPORT.fwIndicators [WFS_SIU_OPENCLOSE]																				
	WFSSIUSETDOOR.wDoor																											
	WFSSIUSETINDICATOR.wCommand																									
	WFSSIUPORTEVENT.wPortStatus																									
	WFSSIUPORTERROR.wPortStatus */																								
	static std::string get_siu__openclose(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_CLOSED)								_str.append("WFS_SIU_CLOSED ");									
		if (macro & WFS_SIU_OPEN)								_str.append("WFS_SIU_OPEN ");									
		if (macro & WFS_SIU_LOCKED)								_str.append("WFS_SIU_LOCKED ");									
		if (macro & WFS_SIU_BOLTED)								_str.append("WFS_SIU_BOLTED ");									
		if (macro & WFS_SIU_SERVICE)							_str.append("WFS_SIU_SERVICE ");								
		if (macro & WFS_SIU_KEYBOARD)							_str.append("WFS_SIU_KEYBOARD ");								
		if (macro & WFS_SIU_AJAR)								_str.append("WFS_SIU_AJAR ");									
		if (macro & WFS_SIU_JAMMED)								_str.append("WFS_SIU_JAMMED ");									
																																
		if (macro == WFS_SIU_NOT_AVAILABLE)						_str.assign("WFS_SIU_NOT_AVAILABLE ");							
																																
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwIndicators [WFS_SIU_AUDIO]																		
	WFSSIUSETPORT.fwIndicators [WFS_SIU_AUDIO]																					
	WFSSIUSETINDICATOR.wCommand																									
	WFSSIUPORTEVENT.wPortStatus																									
	WFSSIUPORTERROR.wPortStatus */																								
	static std::string get_siu__audio(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_KEYPRESS)							_str.append("WFS_SIU_KEYPRESS ");								
		if (macro & WFS_SIU_EXCLAMATION)						_str.append("WFS_SIU_EXCLAMATION ");							
		if (macro & WFS_SIU_WARNING)							_str.append("WFS_SIU_WARNING ");								
		if (macro & WFS_SIU_ERROR)								_str.append("WFS_SIU_ERROR ");									
		if (macro & WFS_SIU_CRITICAL)							_str.append("WFS_SIU_CRITICAL ");								
																																
		if (macro == WFS_SIU_NOT_AVAILABLE)						_str.assign("WFS_SIU_NOT_AVAILABLE ");							
																																
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwAuxiliaries [WFS_SIU_REMOTE_STATUS_MONITOR]														
	WFSSIUSETPORT.fwAuxiliaries [WFS_SIU_REMOTE_STATUS_MONITOR]																	
	WFSSIUSETAUXILIARY.fwCommand																								
	WFSSIUPORTEVENT.wPortStatus																									
	WFSSIUPORTERROR.wPortStatus */																								
	static std::string get_siu__remotestatusmonitor(DWORD macro)																
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_GREEN_LED_ON)						_str.append("WFS_SIU_GREEN_LED_ON ");							
		if (macro & WFS_SIU_GREEN_LED_OFF)						_str.append("WFS_SIU_GREEN_LED_OFF ");							
		if (macro & WFS_SIU_AMBER_LED_ON)						_str.append("WFS_SIU_AMBER_LED_ON ");							
		if (macro & WFS_SIU_AMBER_LED_OFF)						_str.append("WFS_SIU_AMBER_LED_OFF ");							
		if (macro & WFS_SIU_RED_LED_ON)							_str.append("WFS_SIU_RED_LED_ON ");								
		if (macro & WFS_SIU_RED_LED_OFF)						_str.append("WFS_SIU_RED_LED_OFF ");							
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwAuxiliaries [WFS_SIU_ENHANCEDAUDIOCONTROL]														
	WFSSIUSETPORT.fwAuxiliaries [WFS_SIU_ENHANCEDAUDIOCONTROL]																	
	WFSSIUSETAUXILIARY.fwCommand																								
	WFSSIUPORTEVENT.wPortStatus																									
	WFSSIUPORTERROR.wPortStatus */																								
	static std::string get_siu_status_enhancedaudiocontrol(DWORD macro)															
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_PUBLICAUDIO_MANUAL)					_str.append("WFS_SIU_PUBLICAUDIO_MANUAL ");						
		if (macro & WFS_SIU_PUBLICAUDIO_AUTO)					_str.append("WFS_SIU_PUBLICAUDIO_AUTO ");						
		if (macro & WFS_SIU_PUBLICAUDIO_SEMI_AUTO)				_str.append("WFS_SIU_PUBLICAUDIO_SEMI_AUTO ");					
		if (macro & WFS_SIU_PRIVATEAUDIO_MANUAL)				_str.append("WFS_SIU_PRIVATEAUDIO_MANUAL ");					
		if (macro & WFS_SIU_PRIVATEAUDIO_AUTO)					_str.append("WFS_SIU_PRIVATEAUDIO_AUTO ");						
		if (macro & WFS_SIU_PRIVATEAUDIO_SEMI_AUTO)				_str.append("WFS_SIU_PRIVATEAUDIO_SEMI_AUTO ");					
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwSensors [...]																					
	WFSSIUSTATUS.fwIndicators [...]																								
	WFSSIUSTATUS.fwAuxiliaries [...]																							
	WFSSIUSTATUS.fwGuidLights [...]																								
	WFSSIUCAPS.fwSensors [...]																									
	WFSSIUCAPS.fwIndicators [...]																								
	WFSSIUCAPS.fwGuidLights [...]																								
	WFSSIUSETPORT.fwIndicators [...]																							
	WFSSIUSETPORT.fwAuxiliaries [...]																							
	WFSSIUSETPORT.fwGuidLights [...]																							
	WFSSIUSETINDICATORS.fwCommand [...]																							
	WFSSIUSETAUXILIARY.fwCommand [...]																							
	WFSSIUSETGUIDLIGHTS.fwCommand [...]																							
	WFSSIUPORTEVENT.wPortStatus																									
	WFSSIUPORTERROR.wPortStatus */																								
	static std::string get_siu__onoff(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_OFF)								_str.append("WFS_SIU_OFF ");									
		if (macro & WFS_SIU_ON)									_str.append("WFS_SIU_ON ");										
		if (macro & WFS_SIU_SLOW_FLASH)							_str.append("WFS_SIU_SLOW_FLASH ");								
		if (macro & WFS_SIU_MEDIUM_FLASH)						_str.append("WFS_SIU_MEDIUM_FLASH ");							
		if (macro & WFS_SIU_QUICK_FLASH)						_str.append("WFS_SIU_QUICK_FLASH ");							
		if (macro & WFS_SIU_CONTINUOUS)							_str.append("WFS_SIU_CONTINUOUS ");								
																																
		if (macro == WFS_SIU_NOT_AVAILABLE)						_str.assign("WFS_SIU_NOT_AVAILABLE ");							
																																
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwSensors [WFS_SIU_PROXIMITY]																		
	WFSSIUSTATUS.fwSensors [WFS_SIU_ENHANCEDCONTROL]																			
	WFSSIUPORTEVENT.wPortStatus																									
	WFSSIUPORTERROR.wPortStatus */																								
	static std::string get_siu__proximity(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_PRESENT)							_str.append("WFS_SIU_PRESENT ");								
		if (macro & WFS_SIU_NOT_PRESENT)						_str.append("WFS_SIU_NOT_PRESENT ");							
																																
		if (macro == WFS_SIU_NOT_AVAILABLE)						_str.assign("WFS_SIU_NOT_AVAILABLE ");							
																																
		return _str;																											
	}																															
																																
	/* Values of WFSSIUCAPS.fwSensors [WFS_SIU_ENHANCEDAUDIO] */																
	static std::string get_siu__enhancedaudio(DWORD macro)																		
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_MANUAL)								_str.append("WFS_SIU_MANUAL ");									
		if (macro & WFS_SIU_AUTO)								_str.append("WFS_SIU_AUTO ");									
		if (macro & WFS_SIU_SEMI_AUTO)							_str.append("WFS_SIU_SEMI_AUTO ");								
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwSensors [WFS_SIU_AMBLIGHT]																		
	WFSSIUCAPS.fwSensors [WFS_SIU_AMBLIGHT]																						
	WFSSIUPORTEVENT.fwPortStatus																								
	WFSSIUPORTERROR.fwPortStatus */																								
	static std::string get_siu__amblight(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_VERY_DARK)							_str.append("WFS_SIU_VERY_DARK ");								
		if (macro & WFS_SIU_DARK)								_str.append("WFS_SIU_DARK ");									
		if (macro & WFS_SIU_MEDIUM_LIGHT)						_str.append("WFS_SIU_MEDIUM_LIGHT ");							
		if (macro & WFS_SIU_LIGHT)								_str.append("WFS_SIU_LIGHT ");									
		if (macro & WFS_SIU_VERY_LIGHT)							_str.append("WFS_SIU_VERY_LIGHT ");								
																																
		if (macro == WFS_SIU_NOT_AVAILABLE)						_str.assign("WFS_SIU_NOT_AVAILABLE ");							
																																
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSTATUS.fwAuxiliaries [WFS_SIU_UPS]																		
	WFSSIUCAPS.fwAuxiliaries [WFS_SIU_UPS]																						
	WFSSIUPORTEVENT.wPortStatus																									
	WFSSIUPORTERROR.wPortStatus */																								
	static std::string get_siu__upssatatus(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_LOW)								_str.append("WFS_SIU_LOW ");									
		if (macro & WFS_SIU_ENGAGED)							_str.append("WFS_SIU_ENGAGED ");								
		if (macro & WFS_SIU_POWERING)							_str.append("WFS_SIU_POWERING ");								
		if (macro & WFS_SIU_RECOVERED)							_str.append("WFS_SIU_RECOVERED ");								
		return _str;																											
	}																															
																																
	/* Values of WFSSIUCAPS.fwType */																							
	static std::string get_siu_fwType(DWORD macro)																				
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_SENSORS)							_str.append("WFS_SIU_SENSORS ");								
		if (macro & WFS_SIU_DOORS)								_str.append("WFS_SIU_DOORS ");									
		if (macro & WFS_SIU_INDICATORS)							_str.append("WFS_SIU_INDICATORS ");								
		if (macro & WFS_SIU_AUXILIARIES)						_str.append("WFS_SIU_AUXILIARIES ");							
		if (macro & WFS_SIU_GUIDLIGHTS)							_str.append("WFS_SIU_GUIDLIGHTS ");								
		return _str;																											
	}																															
																																
	/* Values of WFSSIUCAPS.fwAuxiliaries [WFS_SIU_ENHANCEDAUDIOCONTROL] */														
	static std::string get_siu_caps_enhancedaudiocontrol(DWORD macro)															
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_HEADSET_DETECTION)					_str.append("WFS_SIU_HEADSET_DETECTION ");						
		if (macro & WFS_SIU_MODE_CONTROLLABLE)					_str.append("WFS_SIU_MODE_CONTROLLABLE ");						
		return _str;																											
	}																															
																																
	/* Values of WFSSIUENABLE.fwSensors [...]																					
	WFSSIUENABLE.fwDoors [...]																									
	WFSSIUENABLE.fwIndicators [...]																								
	WFSSIUENABLE.fwAuxiliaries [...]																							
	WFSSIUENABLE.fwGuidLights [...]																								
	WFSSIUSETPORTS.fwDoors [...]																								
	WFSSIUSETPORTS.fwIndicators [...]																							
	WFSSIUSETPORTS.fwAuxiliaries [...]																							
	WFSSIUSETPORTS.fwGuidLights [...] */																						
	static std::string get_siu__changemode(DWORD macro)
	{
		std::string _str{};
		if (macro & WFS_SIU_NO_CHANGE)							_str.append("WFS_SIU_NO_CHANGE ");
		if (macro & WFS_SIU_ENABLE_EVENT)						_str.append("WFS_SIU_ENABLE_EVENT ");
		if (macro & WFS_SIU_DISABLE_EVENT)						_str.append("WFS_SIU_DISABLE_EVENT ");
		return _str;
	}
																																
	/* Values of WFSSIUSETPORTS.fwDoors [...]																					
	WFSSIUSETDOORS.fwCommand [...] */																							
	static std::string get_siu__boltmode(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_BOLT)								_str.append("WFS_SIU_BOLT ");									
		if (macro & WFS_SIU_UNBOLT)								_str.append("WFS_SIU_UNBOLT ");									
		return _str;																											
	}																															
																																
	/* Values of WFSSIUSETPORTS.fwAuxiliaries [WFS_SIU_UPS]																		
	WFSSIUSETAUXILIARY.wAuxiliary [WFS_SIU_UPS] */																				
	static std::string get_siu__upsmode(DWORD macro)																			
	{																															
		std::string _str{};																										
		if (macro & WFS_SIU_ENGAGE)								_str.append("WFS_SIU_ENGAGE ");									
		if (macro & WFS_SIU_DISENGAGE)							_str.append("WFS_SIU_DISENGAGE ");								
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS VDM Macros */																										
	/*=================================================================*/														
																																
	/* values of WFSVDMSTATUS.wDevice */																						
	static std::string get_vdm_wDevice(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_VDM_DEVONLINE									: _str.assign("WFS_VDM_DEVONLINE");								break;
		case WFS_VDM_DEVOFFLINE									: _str.assign("WFS_VDM_DEVOFFLINE");							break;
		default													: _str.assign("Unknown wDevice");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSVDMSTATUS.wService */																						
	static std::string get_vdm_wService(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_VDM_ENTERPENDING								: _str.assign("WFS_VDM_ENTERPENDING");							break;
		case WFS_VDM_ACTIVE										: _str.assign("WFS_VDM_ACTIVE");								break;
		case WFS_VDM_EXITPENDING								: _str.assign("WFS_VDM_EXITPENDING");							break;
		case WFS_VDM_INACTIVE									: _str.assign("WFS_VDM_INACTIVE");								break;
		default													: _str.assign("Unknown wService");								break;
		}																														
		return _str;																											
	}																															
																																
	/*=================================================================*/														
	/* XFS CAM Macros */																										
	/*=================================================================*/														
																																
	/* values of WFSCAMSTATUS.fwDevice */
	static std::string get_cam_fwDevice(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CAM_DEVONLINE									: _str.assign("WFS_CAM_DEVONLINE");								break;
		case WFS_CAM_DEVOFFLINE									: _str.assign("WFS_CAM_DEVOFFLINE");							break;
		case WFS_CAM_DEVPOWEROFF								: _str.assign("WFS_CAM_DEVPOWEROFF");							break;
		case WFS_CAM_DEVNODEVICE								: _str.assign("WFS_CAM_DEVNODEVICE");							break;
		case WFS_CAM_DEVHWERROR									: _str.assign("WFS_CAM_DEVHWERROR");							break;
		case WFS_CAM_DEVUSERERROR								: _str.assign("WFS_CAM_DEVUSERERROR");							break;
		case WFS_CAM_DEVBUSY									: _str.assign("WFS_CAM_DEVBUSY");								break;
		default													: _str.assign("Unknown fwDevice");								break;
		}																														
		return _str;																											
	}																															
																																
	/* indices of WFSCAMSTATUS.fwMedia[...]																						
	WFSCAMSTATUS.fwCameras [...]																								
	WFSCAMSTATUS.fwPictures[...]																								
	WFSCAMCAPS.fwCameras [...]																									
	WFSCAMTAKEPICT.wCamera */																									
	static std::string get_cam_fwMedia_index(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CAM_ROOM										: _str.assign("WFS_CAM_ROOM");									break;
		case WFS_CAM_PERSON										: _str.assign("WFS_CAM_PERSON");								break;
		case WFS_CAM_EXITSLOT									: _str.assign("WFS_CAM_EXITSLOT");								break;
		default													: _str.assign("Unknown fwMedia index");							break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCAMSTATUS.fwMedia */																						
	static std::string get_cam_fwMedia(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CAM_MEDIAOK									: _str.assign("WFS_CAM_MEDIAOK");								break;
		case WFS_CAM_MEDIAHIGH									: _str.assign("WFS_CAM_MEDIAHIGH");								break;
		case WFS_CAM_MEDIAFULL									: _str.assign("WFS_CAM_MEDIAFULL");								break;
		case WFS_CAM_MEDIAUNKNOWN								: _str.assign("WFS_CAM_MEDIAUNKNOWN");							break;
		case WFS_CAM_MEDIANOTSUPP								: _str.assign("WFS_CAM_MEDIANOTSUPP");							break;
		default													: _str.assign("Unknown fwMedia");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCAMSTATUS.fwCameras */																						
	static std::string get_cam_status_fwCameras(DWORD macro)																	
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CAM_CAMNOTSUPP									: _str.assign("WFS_CAM_CAMNOTSUPP");							break;
		case WFS_CAM_CAMOK										: _str.assign("WFS_CAM_CAMOK");									break;
		case WFS_CAM_CAMINOP									: _str.assign("WFS_CAM_CAMINOP");								break;
		case WFS_CAM_CAMUNKNOWN									: _str.assign("WFS_CAM_CAMUNKNOWN");							break;
		default													: _str.assign("Unknown fwMedia");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCAMCAPS.fwType */																							
	static std::string get_cam_fwType(DWORD macro)																				
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CAM_TYPE_CAM									: _str.assign("WFS_CAM_TYPE_CAM");								break;
		default													: _str.assign("Unknown fwType");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCAMCAPS.fwCameras */																						
	static std::string get_cam_caps_fwCameras(DWORD macro)																		
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CAM_NOT_AVAILABLE								: _str.assign("WFS_CAM_NOT_AVAILABLE");							break;
		case WFS_CAM_AVAILABLE									: _str.assign("WFS_CAM_AVAILABLE");								break;
		default													: _str.assign("Unknown fwCameras");								break;
		}																														
		return _str;																											
	}																															
																																
	/* values of WFSCAMCAPS.fwCamData */																						
	static std::string get_cam_caps_fwCamData(DWORD macro)																		
	{
		std::string _str{};
		if (macro & WFS_CAM_NOTADD)								_str.append("WFS_CAM_NOTADD ");
		if (macro & WFS_CAM_AUTOADD)							_str.append("WFS_CAM_AUTOADD ");
		if (macro & WFS_CAM_MANADD)								_str.append("WFS_CAM_MANADD ");
		return _str;
	}

	/* values of WFSCAMCAPS.fwCharSupport, WFSCAMTAKEPICT.fwCharSupport */
	static std::string get_cam_fwCharSupport(DWORD macro)
	{
		std::string _str{};
		if (macro & WFS_CAM_ASCII)								_str.append("WFS_CAM_ASCII ");
		if (macro & WFS_CAM_UNICODE)							_str.append("WFS_CAM_UNICODE ");
		return _str;
	}

	/*=================================================================*/
	/* XFS CIM Macros */
	/*=================================================================*/
	
	/* values of WFSCIMSTATUS.fwDevice */
	static std::string get_cim_fwDevice(DWORD macro)																			
	{																															
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CIM_DEVONLINE									: _str.assign("WFS_CIM_DEVONLINE");								break;
		case WFS_CIM_DEVOFFLINE									: _str.assign("WFS_CIM_DEVOFFLINE");							break;
		case WFS_CIM_DEVPOWEROFF								: _str.assign("WFS_CIM_DEVPOWEROFF");							break;
		case WFS_CIM_DEVNODEVICE								: _str.assign("WFS_CIM_DEVNODEVICE");							break;
		case WFS_CIM_DEVHWERROR									: _str.assign("WFS_CIM_DEVHWERROR");							break;
		case WFS_CIM_DEVUSERERROR								: _str.assign("WFS_CIM_DEVUSERERROR");							break;
		case WFS_CIM_DEVBUSY									: _str.assign("WFS_CIM_DEVBUSY");								break;
		default													: _str.assign("Unknown fwDevice");								break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMSTATUS.fwSafeDoor */
	static std::string get_cim_fwSafeDoor(DWORD macro)																			
	{						
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CIM_DOORNOTSUPPORTED							: _str.assign("WFS_CIM_DOORNOTSUPPORTED");						break;
		case WFS_CIM_DOOROPEN									: _str.assign("WFS_CIM_DOOROPEN");								break;
		case WFS_CIM_DOORCLOSED									: _str.assign("WFS_CIM_DOORCLOSED");							break;
		case WFS_CIM_DOORUNKNOWN								: _str.assign("WFS_CIM_DOORUNKNOWN");							break;
		default													: _str.assign("Unknown fwSafeDoor");							break;
		}																														
		return _str;																											
	}
	
	/* values of WFSCIMSTATUS.fwAcceptor */
	static std::string get_cim_fwAcceptor(DWORD macro)
	{						
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CIM_ACCOK										: _str.assign("WFS_CIM_ACCOK");									break;
		case WFS_CIM_ACCCUSTATE									: _str.assign("WFS_CIM_ACCCUSTATE");							break;
		case WFS_CIM_ACCCUSTOP									: _str.assign("WFS_CIM_ACCCUSTOP");								break;
		case WFS_CIM_ACCCUUNKNOWN								: _str.assign("WFS_CIM_ACCCUUNKNOWN");							break;
		default													: _str.assign("Unknown fwAcceptor");							break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMSTATUS.fwIntermediateStacker */
	static std::string get_cim_fwIntermediateStacker(DWORD macro)
	{						
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CIM_ISEMPTY									: _str.assign("WFS_CIM_ISEMPTY");								break;
		case WFS_CIM_ISNOTEMPTY									: _str.assign("WFS_CIM_ISNOTEMPTY");							break;
		case WFS_CIM_ISFULL										: _str.assign("WFS_CIM_ISFULL");								break;
		case WFS_CIM_ISUNKNOWN									: _str.assign("WFS_CIM_ISUNKNOWN");								break;
		case WFS_CIM_ISNOTSUPPORTED								: _str.assign("WFS_CIM_ISNOTSUPPORTED");						break;
		default													: _str.assign("Unknown fwIntermediateStacker");					break;
		}																														
		return _str;																											
	}
	
	/* values of WFSCIMSTATUS.fwStackerItems */
	static std::string get_cim_fwStackerItems(DWORD macro)
	{						
		std::string _str;																										
		switch (macro)																											
		{																														
		case WFS_CIM_CUSTOMERACCESS								: _str.assign("WFS_CIM_CUSTOMERACCESS");						break;
		case WFS_CIM_NOCUSTOMERACCESS							: _str.assign("WFS_CIM_NOCUSTOMERACCESS");						break;
		case WFS_CIM_ACCESSUNKNOWN								: _str.assign("WFS_CIM_ACCESSUNKNOWN");							break;
		case WFS_CIM_NOITEMS									: _str.assign("WFS_CIM_NOITEMS");								break;
		default													: _str.assign("Unknown fwStackerItems");						break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMSTATUS.fwBankNoteReader */
	static std::string get_cim_fwBankNoteReader(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_BNROK										: _str.assign("WFS_CIM_BNROK");									break;
		case WFS_CIM_BNRINOP									: _str.assign("WFS_CIM_BNRINOP");								break;
		case WFS_CIM_BNRUNKNOWN									: _str.assign("WFS_CIM_BNRUNKNOWN");							break;
		case WFS_CIM_BNRNOTSUPPORTED							: _str.assign("WFS_CIM_BNRNOTSUPPORTED");						break;
		default													: _str.assign("Unknown fwBankNoteReader");						break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMSTATUS.fwShutter */
	static std::string get_cim_fwShutter(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_SHTCLOSED									: _str.assign("WFS_CIM_SHTCLOSED");								break;
		case WFS_CIM_SHTOPEN									: _str.assign("WFS_CIM_SHTOPEN");								break;
		case WFS_CIM_SHTJAMMED									: _str.assign("WFS_CIM_SHTJAMMED");								break;
		case WFS_CIM_SHTUNKNOWN									: _str.assign("WFS_CIM_SHTUNKNOWN");							break;
		case WFS_CIM_SHTNOTSUPPORTED							: _str.assign("WFS_CIM_SHTNOTSUPPORTED");						break;
		default													: _str.assign("Unknown fwShutter");								break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMINPOS.fwPositionStatus */
	static std::string get_cim_fwPositionStatus(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_PSEMPTY									: _str.assign("WFS_CIM_PSEMPTY");								break;
		case WFS_CIM_PSNOTEMPTY									: _str.assign("WFS_CIM_PSNOTEMPTY");							break;
		case WFS_CIM_PSUNKNOWN									: _str.assign("WFS_CIM_PSUNKNOWN");								break;
		case WFS_CIM_PSNOTSUPPORTED								: _str.assign("WFS_CIM_PSNOTSUPPORTED");						break;
		default													: _str.assign("Unknown fwPositionStatus");						break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMSTATUS.fwTransport */
	static std::string get_cim_fwTransport(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_TPOK										: _str.assign("WFS_CIM_TPOK");									break;
		case WFS_CIM_TPINOP										: _str.assign("WFS_CIM_TPINOP");								break;
		case WFS_CIM_TPUNKNOWN									: _str.assign("WFS_CIM_TPUNKNOWN");								break;
		case WFS_CIM_TPNOTSUPPORTED								: _str.assign("WFS_CIM_TPNOTSUPPORTED");						break;
		default													: _str.assign("Unknown fwTransport");							break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMINPOS.fwTransportStatus */
	static std::string get_cim_fwTransportStatus(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_TPSTATEMPTY								: _str.assign("WFS_CIM_TPSTATEMPTY");							break;
		case WFS_CIM_TPSTATNOTEMPTY								: _str.assign("WFS_CIM_TPSTATNOTEMPTY");						break;
		case WFS_CIM_TPSTATNOTEMPTYCUST							: _str.assign("WFS_CIM_TPSTATNOTEMPTYCUST");					break;
		case WFS_CIM_TPSTATNOTEMPTY_UNK							: _str.assign("WFS_CIM_TPSTATNOTEMPTY_UNK");					break;
		case WFS_CIM_TPSTATNOTSUPPORTED							: _str.assign("WFS_CIM_TPSTATNOTSUPPORTED");					break;
		default													: _str.assign("Unknown fwTransportStatus");						break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMCAPS.fwType */
	static std::string get_cim_caps_fwType(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_TELLERBILL									: _str.assign("WFS_CIM_TELLERBILL");							break;
		case WFS_CIM_SELFSERVICEBILL							: _str.assign("WFS_CIM_SELFSERVICEBILL");						break;
		case WFS_CIM_TELLERCOIN									: _str.assign("WFS_CIM_TELLERCOIN");							break;
		case WFS_CIM_SELFSERVICECOIN							: _str.assign("WFS_CIM_SELFSERVICECOIN");						break;
		default													: _str.assign("Unknown fwType");								break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMCAPS.fwExchangeType */
	/* values of WFSCIMSTARTEX.fwExchangeType */
	static std::string get_cim_fwExchangeType(DWORD macro)
	{
		std::string _str{};
		if (macro & WFS_CIM_EXBYHAND)							_str.append("WFS_CIM_EXBYHAND ");
		if (macro & WFS_CIM_EXTOCASSETTES)						_str.append("WFS_CIM_EXTOCASSETTES ");
		if (macro & WFS_CIM_CLEARRECYCLER)						_str.append("WFS_CIM_CLEARRECYCLER ");
		if (macro & WFS_CIM_DEPOSITINTO)						_str.append("WFS_CIM_DEPOSITINTO ");
		return _str;
	}

	/* values of WFSCIMCAPS.fwRetractTransportActions */
	/* values of WFSCIMCAPS.fwRetractStackerActions */
	static std::string get_cim_fwRetractTransportActions(DWORD macro)
	{
		std::string _str{};
		if (macro & WFS_CIM_PRESENT)							_str.append("WFS_CIM_PRESENT ");
		if (macro & WFS_CIM_RETRACT)							_str.append("WFS_CIM_RETRACT ");
		if (macro & WFS_CIM_NOTSUPP)							_str.append("WFS_CIM_NOTSUPP ");
		return _str;
	}

	/* values of WFSCIMCASHIN.fwType */
	static std::string get_cim_cashin_fwType_gui(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_TYPERECYCLING								: _str.assign("REC");											break;
		case WFS_CIM_TYPECASHIN									: _str.assign("CIN");											break;
		case WFS_CIM_TYPEREPCONTAINER							: _str.assign("REPCONTAINER");									break;
		case WFS_CIM_TYPERETRACTCASSETTE						: _str.assign("RET");											break;
		default													: _str.assign("Unknown");										break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMCASHIN.fwType */
	static std::string get_cim_cashin_fwType(DWORD macro)
	{						
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_TYPERECYCLING								: _str.assign("WFS_CIM_TYPERECYCLING");							break;
		case WFS_CIM_TYPECASHIN									: _str.assign("WFS_CIM_TYPECASHIN");							break;
		case WFS_CIM_TYPEREPCONTAINER							: _str.assign("WFS_CIM_TYPEREPCONTAINER");						break;
		case WFS_CIM_TYPERETRACTCASSETTE						: _str.assign("WFS_CIM_TYPEREPCONTAINER");						break;
		default													: _str.assign("Unknown fwType");								break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMCASHIN.fwItemType */
	/* values of WFSCIMCASHINTYPE.dwType */
	static std::string get_cim_fwItemType(DWORD macro)
	{
		std::string _str{};
		if (macro & WFS_CIM_CITYPALL)							_str.append("WFS_CIM_CITYPALL ");
		if (macro & WFS_CIM_CITYPUNFIT)							_str.append("WFS_CIM_CITYPUNFIT ");
		if (macro & WFS_CIM_CITYPINDIVIDUAL)					_str.append("WFS_CIM_CITYPINDIVIDUAL ");
		if (macro & WFS_CIM_CITYPLEVEL3)						_str.append("WFS_CIM_CITYPLEVEL3 ");
		if (macro & WFS_CIM_CITYPLEVEL2)						_str.append("WFS_CIM_CITYPLEVEL2 ");
		return _str;
	}

	/* values of WFSCIMCASHIN.usStatus */
	/* values of WFSCIMPHCU.usPStatus */
	static std::string get_cim_usStatus_gui(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_STATCUOK									: _str.assign("CUOK");											break;
		case WFS_CIM_STATCUFULL									: _str.assign("CUFULL");										break;
		case WFS_CIM_STATCUHIGH									: _str.assign("CUHIGH");										break;
		case WFS_CIM_STATCULOW									: _str.assign("CULOW");											break;
		case WFS_CIM_STATCUEMPTY								: _str.assign("CUEMPTY");										break;
		case WFS_CIM_STATCUINOP									: _str.assign("CUINOP");										break;
		case WFS_CIM_STATCUMISSING								: _str.assign("CUMISS");										break;
		case WFS_CIM_STATCUNOVAL								: _str.assign("CUNOVAL");										break;
		case WFS_CIM_STATCUNOREF								: _str.assign("CUNOREF");										break;
		case WFS_CIM_STATCUMANIP								: _str.assign("CUMANIP");										break;
		default													: _str.assign("Unknown");										break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMCASHIN.usStatus */
	/* values of WFSCIMPHCU.usPStatus */
	static std::string get_cim_usStatus(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_STATCUOK									: _str.assign("WFS_CIM_STATCUOK");								break;
		case WFS_CIM_STATCUFULL									: _str.assign("WFS_CIM_STATCUFULL");							break;
		case WFS_CIM_STATCUHIGH									: _str.assign("WFS_CIM_STATCUHIGH");							break;
		case WFS_CIM_STATCULOW									: _str.assign("WFS_CIM_STATCULOW");								break;
		case WFS_CIM_STATCUEMPTY								: _str.assign("WFS_CIM_STATCUEMPTY");							break;
		case WFS_CIM_STATCUINOP									: _str.assign("WFS_CIM_STATCUINOP");							break;
		case WFS_CIM_STATCUMISSING								: _str.assign("WFS_CIM_STATCUMISSING");							break;
		case WFS_CIM_STATCUNOVAL								: _str.assign("WFS_CIM_STATCUNOVAL");							break;
		case WFS_CIM_STATCUNOREF								: _str.assign("WFS_CIM_STATCUNOREF");							break;
		case WFS_CIM_STATCUMANIP								: _str.assign("WFS_CIM_STATCUMANIP");							break;
		default													: _str.assign("Unknown");										break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMSTATUS.fwPositions */
	/* values of WFSCIMCAPS.fwPositions */
	/* values of WFSCIMINPOS.fwPosition */
	/* values of WFSCIMTELLERDETAILS.fwInputPosition */
	/* values of WFSCIMCASHINSTART.fwInputPosition */

	/* values of WFSCIMSTATUS.fwPositions */
	/* values of WFSCIMCAPS.fwPositions */
	/* values of WFSCIMTELLERDETAILS.fwOutputPosition */
	/* values of WFSCIMCASHINSTART.fwOutputPosition */
	/* values of WFSCIMOUTPUT.fwPosition */
	static std::string get_cim_fwPositions(DWORD macro)
	{
		std::string _str{};
		if (macro & WFS_CIM_POSNULL)							_str.append("WFS_CIM_POSNULL ");
		if (macro & WFS_CIM_POSINLEFT)							_str.append("WFS_CIM_POSINLEFT ");
		if (macro & WFS_CIM_POSINRIGHT)							_str.append("WFS_CIM_POSINRIGHT ");
		if (macro & WFS_CIM_POSINCENTER)						_str.append("WFS_CIM_POSINCENTER ");
		if (macro & WFS_CIM_POSINTOP)							_str.append("WFS_CIM_POSINTOP ");
		if (macro & WFS_CIM_POSINBOTTOM)						_str.append("WFS_CIM_POSINBOTTOM ");
		if (macro & WFS_CIM_POSINFRONT)							_str.append("WFS_CIM_POSINFRONT ");
		if (macro & WFS_CIM_POSINREAR)							_str.append("WFS_CIM_POSINREAR ");
		if (macro & WFS_CIM_POSOUTLEFT)							_str.append("WFS_CIM_POSOUTLEFT ");
		if (macro & WFS_CIM_POSOUTRIGHT)						_str.append("WFS_CIM_POSOUTRIGHT ");
		if (macro & WFS_CIM_POSOUTCENTER)						_str.append("WFS_CIM_POSOUTCENTER ");
		if (macro & WFS_CIM_POSOUTTOP)							_str.append("WFS_CIM_POSOUTTOP ");
		if (macro & WFS_CIM_POSOUTBOTTOM)						_str.append("WFS_CIM_POSOUTBOTTOM ");
		if (macro & WFS_CIM_POSOUTFRONT)						_str.append("WFS_CIM_POSOUTFRONT ");
		if (macro & WFS_CIM_POSOUTREAR)							_str.append("WFS_CIM_POSOUTREAR ");
		return _str;
	}

	/* values of WFSCIMCASHINSTATUS.wStatus */
	static std::string get_cim_wStatus(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_CIOK										: _str.assign("WFS_CIM_CIOK");									break;
		case WFS_CIM_CIROLLBACK									: _str.assign("WFS_CIM_CIROLLBACK");							break;
		case WFS_CIM_CIACTIVE									: _str.assign("WFS_CIM_CIACTIVE");								break;
		case WFS_CIM_CIRETRACT									: _str.assign("WFS_CIM_CIRETRACT");								break;
		case WFS_CIM_CIUNKNOWN									: _str.assign("WFS_CIM_CIUNKNOWN");								break;
		default													: _str.assign("Unknown wStatus");								break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMCAPS.fwRetractAreas */
	/* values of WFSCIMRETRACT.usRetractArea */
	static std::string get_cim_fwRetractAreas(DWORD macro)
	{
		std::string _str{};
		if (macro & WFS_CIM_RA_RETRACT)							_str.append("WFS_CIM_RA_RETRACT ");
		if (macro & WFS_CIM_RA_TRANSPORT)						_str.append("WFS_CIM_RA_TRANSPORT ");
		if (macro & WFS_CIM_RA_STACKER)							_str.append("WFS_CIM_RA_STACKER ");
		if (macro & WFS_CIM_RA_BILLCASSETTES)					_str.append("WFS_CIM_RA_BILLCASSETTES ");
		if (macro & WFS_CIM_RA_NOTSUPP)							_str.append("WFS_CIM_RA_NOTSUPP ");
		return _str;
	}

	/* values of WFSCIMP6INFO.usLevel */
	/* values of WFSCIMP6SIGNATURE.usLevel */
	static std::string get_cim_usLevel(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_LEVEL_2									: _str.assign("WFS_CIM_LEVEL_2");								break;
		case WFS_CIM_LEVEL_3									: _str.assign("WFS_CIM_LEVEL_3");								break;
		default													: _str.assign("Unknown usLevel");								break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMTELLERUPDATE.usAction */
	static std::string get_cim_usAction(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_CREATE_TELLER								: _str.assign("WFS_CIM_CREATE_TELLER");							break;
		case WFS_CIM_MODIFY_TELLER								: _str.assign("WFS_CIM_MODIFY_TELLER");							break;
		case WFS_CIM_DELETE_TELLER								: _str.assign("WFS_CIM_DELETE_TELLER");							break;
		default													: _str.assign("Unknown usAction");								break;
		}																														
		return _str;																											
	}

	/* values of WFSCIMCUERROR.wFailure */
	static std::string get_cim_wFailure(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_CASHUNITEMPTY								: _str.assign("WFS_CIM_CASHUNITEMPTY");							break;
		case WFS_CIM_CASHUNITERROR								: _str.assign("WFS_CIM_CASHUNITERROR");							break;
		case WFS_CIM_CASHUNITFULL								: _str.assign("WFS_CIM_CASHUNITFULL");							break;
		case WFS_CIM_CASHUNITLOCKED								: _str.assign("WFS_CIM_CASHUNITLOCKED");						break;
		case WFS_CIM_CASHUNITNOTCONF							: _str.assign("WFS_CIM_CASHUNITNOTCONF");						break;
		case WFS_CIM_CASHUNITINVALID							: _str.assign("WFS_CIM_CASHUNITINVALID");						break;
		case WFS_CIM_CASHUNITCONFIG								: _str.assign("WFS_CIM_CASHUNITCONFIG");						break;
		case WFS_CIM_FEEDMODULEPROBLEM							: _str.assign("WFS_CIM_FEEDMODULEPROBLEM");						break;
		default													: _str.assign("Unknown wFailure");								break;
		}																														
		return _str;																											
	}

	/*values of WFSCIMP6SIGNATURE.dwOrientation*/
	static std::string get_cim_dwOrientation(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_ORFRONTTOP									: _str.assign("WFS_CIM_ORFRONTTOP");							break;
		case WFS_CIM_ORFRONTBOTTOM								: _str.assign("WFS_CIM_ORFRONTBOTTOM");							break;
		case WFS_CIM_ORBACKTOP									: _str.assign("WFS_CIM_ORBACKTOP");								break;
		case WFS_CIM_ORBACKBOTTOM								: _str.assign("WFS_CIM_ORBACKBOTTOM");							break;
		case WFS_CIM_ORUNKNOWN									: _str.assign("WFS_CIM_ORUNKNOWN");								break;
		case WFS_CIM_ORNOTSUPPORTED								: _str.assign("WFS_CIM_ORNOTSUPPORTED");						break;
		default													: _str.assign("Unknown dwOrientation");							break;
		}																														
		return _str;																											
	}

	/* values of lpusReason in WFS_EXEE_CIM_INPUTREFUSE */
	static std::string get_cim_INPUTREFUSE(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_CASHINUNITFULL								: _str.assign("WFS_CIM_CASHINUNITFULL");						break;
		case WFS_CIM_INVALIDBILL								: _str.assign("WFS_CIM_INVALIDBILL");							break;
		case WFS_CIM_NOBILLSTODEPOSIT							: _str.assign("WFS_CIM_NOBILLSTODEPOSIT");						break;
		case WFS_CIM_DEPOSITFAILURE								: _str.assign("WFS_CIM_DEPOSITFAILURE");						break;
		case WFS_CIM_COMMINPCOMPFAILURE							: _str.assign("WFS_CIM_COMMINPCOMPFAILURE");					break;
		case WFS_CIM_STACKERFULL								: _str.assign("WFS_CIM_STACKERFULL");							break;
		default													: _str.assign("Unknown dwOrientation");							break;
		}																														
		return _str;																											
	}

	/* values of lpusReason in WFS_EXEE_CIM_NOTESERROR */
	static std::string get_cim_NOTESERROR(DWORD macro)
	{
		std::string _str;
		switch (macro)
		{																														
		case WFS_CIM_DOUBLENOTEDETECTED							: _str.assign("WFS_CIM_DOUBLENOTEDETECTED");					break;
		case WFS_CIM_LONGNOTEDETECTED							: _str.assign("WFS_CIM_LONGNOTEDETECTED");						break;
		case WFS_CIM_SKEWEDNOTE									: _str.assign("WFS_CIM_SKEWEDNOTE");							break;
		case WFS_CIM_INCORRECTCOUNT								: _str.assign("WFS_CIM_INCORRECTCOUNT");						break;
		case WFS_CIM_NOTESTOOCLOSE								: _str.assign("WFS_CIM_NOTESTOOCLOSE");							break;
		default													: _str.assign("Unknown NOTESERROR");							break;
		}																														
		return _str;																											
	}
} // !__N_DESCRIPTOR__

#endif // !__H_DESCRIPTORS__
