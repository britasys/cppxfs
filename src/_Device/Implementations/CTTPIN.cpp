
#include "CTTPIN.h"

namespace TTDevice
{
	/*=================================================================*/
	/* PIN Info Functions */
	/*=================================================================*/

	bool  CTTPIN::GetStatus(LPTTWFSPINSTATUS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSPINSTATUS>(WFS_INF_PIN_STATUS, NULL, lpOut, Timeout);
	}
	bool  CTTPIN::GetCapabilities(LPTTWFSPINCAPS lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSPINCAPS>(WFS_INF_PIN_CAPABILITIES, NULL, lpOut, Timeout);
	}
	bool  CTTPIN::GetKeyDetail(const LPSTR lpsKeyName, LPTTWFSPINP2APKEYDETAIL lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSPINKEYDETAIL>(WFS_INF_PIN_KEY_DETAIL, lpsKeyName, lpOut, Timeout);
	}
	bool  CTTPIN::GetFuncKeyDetail(const LPULONG lpulFDKMask, LPTTWFSPINFUNCKEYDETAIL lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPULONG, XFS300::LPWFSPINFUNCKEYDETAIL>(WFS_INF_PIN_FUNCKEY_DETAIL, lpulFDKMask, lpOut, Timeout);
	}
	bool  CTTPIN::GetHSMTData(LPTTWFSXDATA lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<nullptr_t, XFS300::LPWFSXDATA>(WFS_INF_PIN_HSM_TDATA, NULL, lpOut, Timeout);
	}
	bool  CTTPIN::GetKeyDetailEx(const LPSTR lpsKeyName, LPTTWFSPINP2APKEYDETAILEX lpOut, const DWORD Timeout) noexcept
	{
		return TTSyncGetInfo<LPSTR, XFS300::LPWFSPINKEYDETAILEX>(WFS_INF_PIN_KEY_DETAIL_EX, lpsKeyName, lpOut, Timeout);
	}

	bool  CTTPIN::AsyncGetStatus(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PIN_STATUS, NULL, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetCapabilities(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PIN_CAPABILITIES, NULL, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetKeyDetail(const LPSTR lpsKeyName, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PIN_KEY_DETAIL, lpsKeyName, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetFuncKeyDetail(const LPULONG lpulFDKMask, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PIN_FUNCKEY_DETAIL, lpulFDKMask, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetHSMTData(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PIN_HSM_TDATA, NULL, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetKeyDetailEx(const LPSTR lpsKeyName, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncGetInfo(WFS_INF_PIN_KEY_DETAIL_EX, lpsKeyName, ReqID, Timeout);
	}

	/*=================================================================*/
	/* PIN Execute Functions */
	/*=================================================================*/

	/// Normal PIN Commands
	bool  CTTPIN::Crypt(const LPTTWFSPINCRYPT lpCrypt, LPTTWFSXDATA lpxCryptData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINCRYPT, XFS300::LPWFSXDATA>(WFS_CMD_PIN_CRYPT, lpCrypt, lpxCryptData, Timeout);
	}
	bool  CTTPIN::ImportKey(const LPTTWFSPINIMPORT lpImport, LPTTWFSXDATA lpxKVC, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINIMPORT, XFS300::LPWFSXDATA>(WFS_CMD_PIN_IMPORT_KEY, lpImport, lpxKVC, Timeout);
	}
	bool  CTTPIN::DeriveKey(const LPTTWFSPINDERIVE lpDerive, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINDERIVE, nullptr_t>(WFS_CMD_PIN_DERIVE_KEY, lpDerive, NULL, Timeout);
	}
	bool  CTTPIN::GetPin(const LPTTWFSPINGETPIN lpPIN, LPTTWFSPINENTRY lpEntry, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINGETPIN, XFS300::LPWFSPINENTRY>(WFS_CMD_PIN_GET_PIN, lpPIN, lpEntry, Timeout);
	}
	bool  CTTPIN::LocalDES(const LPTTWFSPINLOCALDES lpLocalDES, LPTTWFSPINBOOL lpbResult, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINLOCALDES, LPBOOL>(WFS_CMD_PIN_LOCAL_DES, lpLocalDES, lpbResult, Timeout);
	}
	bool  CTTPIN::CreateOffset(const LPTTWFSPINCREATEOFFSET lpCreateOffset, LPTTWFSPINLPSTR lpsOffset, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINCREATEOFFSET, LPSTR>(WFS_CMD_PIN_CREATE_OFFSET, lpCreateOffset, lpsOffset, Timeout);
	}
	bool  CTTPIN::LocalEuroCheque(const LPTTWFSPINLOCALEUROCHEQUE lpLocalEuroCheque, LPTTWFSPINBOOL lpbResult, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINLOCALEUROCHEQUE, LPBOOL>(WFS_CMD_PIN_LOCAL_EUROCHEQUE, lpLocalEuroCheque, lpbResult, Timeout);
	}
	bool  CTTPIN::LocalVisa(const LPTTWFSPINLOCALVISA lpLocalVisa, LPTTWFSPINBOOL lpbResult, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINLOCALVISA, LPBOOL>(WFS_CMD_PIN_LOCAL_VISA, lpLocalVisa, lpbResult, Timeout);
	}
	bool  CTTPIN::PresentIDC(const LPTTWFSPINPRESENTIDC lpPresentIDC, LPTTWFSPINPRESENTRESULT lpPresentResult, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINPRESENTIDC, XFS300::LPWFSPINPRESENTRESULT>(WFS_CMD_PIN_PRESENT_IDC, lpPresentIDC, lpPresentResult, Timeout);
	}
	bool  CTTPIN::GetPinBlock(const LPTTWFSPINBLOCK lpBlock, LPTTWFSXDATA lpxPinBlock, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINBLOCK, XFS300::LPWFSXDATA>(WFS_CMD_PIN_GET_PINBLOCK, lpBlock, lpxPinBlock, Timeout);
	}
	bool  CTTPIN::GetData(const LPTTWFSPINGETDATA lpGetData, LPTTWFSPINDATA lpPinData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINGETDATA, XFS300::LPWFSPINDATA>(WFS_CMD_PIN_GET_DATA, lpGetData, lpPinData, Timeout);
	}
	bool  CTTPIN::Initialization(const LPTTWFSPININIT lpInit, LPTTWFSXDATA lpxIdentification, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPININIT, XFS300::LPWFSXDATA>(WFS_CMD_PIN_INITIALIZATION, lpInit, lpxIdentification, Timeout);
	}
	bool  CTTPIN::LocalBankSYS(const LPTTWFSPINLOCALBANKSYS lpLocalBankSYS, LPTTWFSPINBOOL lpbResult, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINLOCALBANKSYS, LPBOOL>(WFS_CMD_PIN_LOCAL_BANKSYS, lpLocalBankSYS, lpbResult, Timeout);
	}
	bool  CTTPIN::BankSYSIO(const LPTTWFSPINBANKSYSIO lpBankSYSIO, LPTTWFSPINBANKSYSIO lpBANKSYSIoOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINBANKSYSIO, XFS300::LPWFSPINBANKSYSIO>(WFS_CMD_PIN_BANKSYS_IO, lpBankSYSIO, lpBANKSYSIoOut, Timeout);
	}
	bool  CTTPIN::Reset(const DWORD Timeout) noexcept
	{
		return TTSyncExecute<nullptr_t, nullptr_t>(WFS_CMD_PIN_RESET, NULL, NULL, Timeout);
	}
	bool  CTTPIN::HSMSetTData(const LPTTWFSXDATA lpxTData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSXDATA, nullptr_t>(WFS_CMD_PIN_HSM_SET_TDATA, lpxTData, NULL, Timeout);
	}
	bool  CTTPIN::SecureMSGSend(const LPTTWFSPINSECMSG lpSecMsgIn, LPTTWFSPINSECMSG lpSecMsgOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINSECMSG, XFS300::LPWFSPINSECMSG>(WFS_CMD_PIN_SECURE_MSG_SEND, lpSecMsgIn, lpSecMsgOut, Timeout);
	}
	bool  CTTPIN::SecureMSGReceive(const LPTTWFSPINSECMSG lpSecMsgIn, const DWORD Timeout) noexcept
	{
		return TTSyncExecute < XFS300::LPWFSPINSECMSG,  nullptr_t > (WFS_CMD_PIN_SECURE_MSG_RECEIVE, lpSecMsgIn, NULL, Timeout);
	}
	bool  CTTPIN::GetJournal(LPWORD lpwProtocol, LPTTWFSXDATA lpxJournalData, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<LPWORD, XFS300::LPWFSXDATA>(WFS_CMD_PIN_GET_JOURNAL, lpwProtocol, lpxJournalData, Timeout);
	}
	bool  CTTPIN::ImportKeyEx(const LPTTWFSPINIMPORTKEYEX lpImportKeyEx, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINIMPORTKEYEX, nullptr_t>(WFS_CMD_PIN_IMPORT_KEY_EX, lpImportKeyEx, NULL, Timeout);
	}
	bool  CTTPIN::ENCIO(const LPTTWFSPINENCIO lpEncIoIn, LPTTWFSPINENCIO  lpEncIoOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINENCIO, XFS300::LPWFSPINENCIO>(WFS_CMD_PIN_ENC_IO, lpEncIoIn, lpEncIoOut, Timeout);
	}
	bool  CTTPIN::HSMInit(const LPTTWFSPINHSMINIT lpHsmInit, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINHSMINIT, nullptr_t>(WFS_CMD_PIN_HSM_INIT, lpHsmInit, NULL, Timeout);
	}

	bool  CTTPIN::AsyncCrypt(const LPTTWFSPINCRYPT lpCrypt, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_CRYPT, lpCrypt, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncImportKey(const LPTTWFSPINIMPORT lpImport, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_IMPORT_KEY, lpImport, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncDeriveKey(const LPTTWFSPINDERIVE lpDerive, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_DERIVE_KEY, lpDerive, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetPin(const LPTTWFSPINGETPIN lpPIN, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_GET_PIN, lpPIN, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncLocalDES(const LPTTWFSPINLOCALDES lpLocalDES, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_LOCAL_DES, lpLocalDES, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncCreateOffset(const LPTTWFSPINCREATEOFFSET lpCreateOffset, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_CREATE_OFFSET, lpCreateOffset, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncLocalEuroCheque(const LPTTWFSPINLOCALEUROCHEQUE lpLocalEuroCheque, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_LOCAL_EUROCHEQUE, lpLocalEuroCheque, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncLocalVisa(const LPTTWFSPINLOCALVISA lpLocalVisa, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_LOCAL_VISA, lpLocalVisa, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncPresentIDC(const LPTTWFSPINPRESENTIDC lpPresentIDC, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_PRESENT_IDC, lpPresentIDC, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetPinBlock(const LPTTWFSPINBLOCK lpBlock, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_GET_PINBLOCK, lpBlock, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetData(const LPTTWFSPINGETDATA lpGetData, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_GET_DATA, lpGetData, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncInitialization(const LPTTWFSPININIT lpInit, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_INITIALIZATION, lpInit, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncLocalBankSYS(const LPTTWFSPINLOCALBANKSYS lpLocalBankSYS, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_LOCAL_BANKSYS, lpLocalBankSYS, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncBankSYSIO(const LPTTWFSPINBANKSYSIO lpBankSYSIO, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_BANKSYS_IO, lpBankSYSIO, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncReset(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_RESET, NULL, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncHSMSetTData(const LPTTWFSXDATA lpxTData, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_HSM_SET_TDATA, lpxTData, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncSecureMSGSend(const LPTTWFSPINSECMSG lpSecMsgIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_SECURE_MSG_SEND, lpSecMsgIn, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncSecureMSGReceive(const LPTTWFSPINSECMSG lpSecMsgIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_SECURE_MSG_RECEIVE, lpSecMsgIn, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetJournal(LPWORD lpwProtocol, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_GET_JOURNAL, lpwProtocol, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncImportKeyEx(const LPTTWFSPINIMPORTKEYEX lpImportKeyEx, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_IMPORT_KEY_EX, lpImportKeyEx, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncENCIO(const LPTTWFSPINENCIO lpEncIoIn, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_ENC_IO, lpEncIoIn, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncHSMInit(const LPTTWFSPINHSMINIT lpHsmInit, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_HSM_INIT, lpHsmInit, ReqID, Timeout);
	}
	/// Common Commands forRemote Key Loading Schemes
	bool  CTTPIN::StartKeyExchange(const LPTTWFSPINSTARTKEYEXCHANGE lpStartKeyExchange, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINSTARTKEYEXCHANGE, nullptr_t>(WFS_CMD_PIN_START_KEY_EXCHANGE, lpStartKeyExchange, NULL, Timeout);
	}

	bool  CTTPIN::AsyncStartKeyExchange(REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_START_KEY_EXCHANGE, NULL, ReqID, Timeout);
	}
	/// Remote Key Loading Using Signature
	bool  CTTPIN::ImportRSAPublicKey(const LPTTWFSPINIMPORTRSAPUBLICKEY lpImportRSAPublicKey, LPTTWFSPINIMPORTRSAPUBLICKEYOUTPUT lpImportRSAPublicKeyOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINIMPORTRSAPUBLICKEY, XFS300::LPWFSPINIMPORTRSAPUBLICKEYOUTPUT>(WFS_CMD_PIN_IMPORT_RSA_PUBLIC_KEY, lpImportRSAPublicKey, lpImportRSAPublicKeyOutput, Timeout);
	}
	bool  CTTPIN::ExportRSAIssuerSignedItem(const LPTTWFSPINEXPORTRSAISSUERSIGNEDITEM lpExportRSAIssuerSignedItem, LPTTWFSPINEXPORTRSAISSUERSIGNEDITEMOUTPUT lpExportRSAIssuerSignedItemOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINEXPORTRSAISSUERSIGNEDITEM, XFS300::LPWFSPINEXPORTRSAISSUERSIGNEDITEMOUTPUT>(WFS_CMD_PIN_EXPORT_RSA_ISSUER_SIGNED_ITEM, lpExportRSAIssuerSignedItem, lpExportRSAIssuerSignedItemOutput, Timeout);
	}
	bool  CTTPIN::ImportRSASignedDESKey(const LPTTWFSPINIMPORTRSASIGNEDDESKEY lpImportRSASignedDESKey, LPTTWFSPINIMPORTRSASIGNEDDESKEYOUTPUT lpImportRSASignedDESKeyOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINIMPORTRSASIGNEDDESKEY, XFS300::LPWFSPINIMPORTRSASIGNEDDESKEYOUTPUT>(WFS_CMD_PIN_IMPORT_RSA_SIGNED_DES_KEY, lpImportRSASignedDESKey, lpImportRSASignedDESKeyOutput, Timeout);
	}
	bool  CTTPIN::GenerateRSAKeyPair(const LPTTWFSPINGENERATERSAKEYPAIR lpGenerateRSAKeyPair, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINGENERATERSAKEYPAIR, nullptr_t>(WFS_CMD_PIN_GENERATE_RSA_KEY_PAIR, lpGenerateRSAKeyPair, NULL, Timeout);
	}
	bool  CTTPIN::ExportRSAEPPSignedItem(const LPTTWFSPINEXPORTRSAEPPSIGNEDITEM lpExportRSAEPPSignedItem, LPTTWFSPINEXPORTRSAEPPSIGNEDITEMOUTPUT lpExportRSAEPPSignedItemOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINEXPORTRSAEPPSIGNEDITEM, XFS300::LPWFSPINEXPORTRSAEPPSIGNEDITEMOUTPUT>(WFS_CMD_PIN_EXPORT_RSA_EPP_SIGNED_ITEM, lpExportRSAEPPSignedItem, lpExportRSAEPPSignedItemOutput, Timeout);
	}

	bool  CTTPIN::AsyncImportRSAPublicKey(const LPTTWFSPINIMPORTRSAPUBLICKEY lpImportRSAPublicKey, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_IMPORT_RSA_PUBLIC_KEY, lpImportRSAPublicKey, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncExportRSAIssuerSignedItem(const LPTTWFSPINEXPORTRSAISSUERSIGNEDITEM lpExportRSAIssuerSignedItem, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_EXPORT_RSA_ISSUER_SIGNED_ITEM, lpExportRSAIssuerSignedItem, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncImportRSASignedDESKey(const LPTTWFSPINIMPORTRSASIGNEDDESKEY lpImportRSASignedDESKey, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_IMPORT_RSA_SIGNED_DES_KEY, lpImportRSASignedDESKey, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGenerateRSAKeyPair(const LPTTWFSPINGENERATERSAKEYPAIR lpGenerateRSAKeyPair, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_GENERATE_RSA_KEY_PAIR, lpGenerateRSAKeyPair, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncExportRSAEPPSignedItem(const LPTTWFSPINEXPORTRSAEPPSIGNEDITEM lpExportRSAEPPSignedItem, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_EXPORT_RSA_EPP_SIGNED_ITEM, lpExportRSAEPPSignedItem, ReqID, Timeout);
	}
	/// Remote Key Loading Using CERTIFICATES
	bool  CTTPIN::LoadCertificate(const LPTTWFSPINLOADCERTIFICATE lpLoadCertificate, LPTTWFSPINLOADCERTIFICATEOUTPUT lpLoadCertificateOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINLOADCERTIFICATE, XFS300::LPWFSPINLOADCERTIFICATEOUTPUT>(WFS_CMD_PIN_LOAD_CERTIFICATE, lpLoadCertificate, lpLoadCertificateOutput, Timeout);
	}
	bool  CTTPIN::GetCertificate(const LPTTWFSPINGETCERTIFICATE lpGetCertificate, LPTTWFSPINGETCERTIFICATEOUTPUT lpGetCertificateOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINGETCERTIFICATE, XFS300::LPWFSPINGETCERTIFICATEOUTPUT>(WFS_CMD_PIN_GET_CERTIFICATE, lpGetCertificate, lpGetCertificateOutput, Timeout);
	}
	bool  CTTPIN::ReplaceCertificate(const LPTTWFSPINREPLACECERTIFICATE lpReplaceCertificate, LPTTWFSPINREPLACECERTIFICATEOUTPUT lpReplaceCertificateOuput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINREPLACECERTIFICATE, XFS300::LPWFSPINREPLACECERTIFICATEOUTPUT>(WFS_CMD_PIN_REPLACE_CERTIFICATE, lpReplaceCertificate, lpReplaceCertificateOuput, Timeout);
	}
	bool  CTTPIN::ImportRSAEncipheredPKCS7Key(const LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY lpImportRSAEncipheredPKCS7Key, LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEYOUTPUT lpImportRSAEncipheredKeyOut, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINIMPORTRSAENCIPHEREDPKCS7KEY, XFS300::LPWFSPINIMPORTRSAENCIPHEREDPKCS7KEYOUTPUT>(WFS_CMD_PIN_IMPORT_RSA_ENCIPHERED_PKCS7_KEY, lpImportRSAEncipheredPKCS7Key, lpImportRSAEncipheredKeyOut, Timeout);
	}

	bool  CTTPIN::AsyncLoadCertificate(const LPTTWFSPINLOADCERTIFICATE lpLoadCertificate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_LOAD_CERTIFICATE, lpLoadCertificate, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncGetCertificate(const LPTTWFSPINGETCERTIFICATE lpGetCertificate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_GET_CERTIFICATE, lpGetCertificate, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncReplaceCertificate(const LPTTWFSPINREPLACECERTIFICATE lpReplaceCertificate, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_REPLACE_CERTIFICATE, lpReplaceCertificate, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncImportRSAEncipheredPKCS7Key(const LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY lpImportRSAEncipheredPKCS7Key, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_IMPORT_RSA_ENCIPHERED_PKCS7_KEY, lpImportRSAEncipheredPKCS7Key, ReqID, Timeout);
	}
	/// EMV
	bool  CTTPIN::EMVImportPublicKey(const LPTTWFSPINEMVIMPORTPUBLICKEY lpEMVImportPublicKey, LPTTWFSPINEMVIMPORTPUBLICKEYOUTPUT lpEMVImportPublicKeyOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINEMVIMPORTPUBLICKEY, XFS300::LPWFSPINEMVIMPORTPUBLICKEYOUTPUT>(WFS_CMD_PIN_EMV_IMPORT_PUBLIC_KEY, lpEMVImportPublicKey, lpEMVImportPublicKeyOutput, Timeout);
	}
	bool  CTTPIN::Digest(const LPTTWFSPINDIGEST lpDigest, LPTTWFSPINDIGESTOUTPUT lpDigestOutput, const DWORD Timeout) noexcept
	{
		return TTSyncExecute<XFS300::LPWFSPINDIGEST, XFS300::LPWFSPINDIGESTOUTPUT>(WFS_CMD_PIN_DIGEST, lpDigest, lpDigestOutput, Timeout);
	}

	bool  CTTPIN::AsyncEMVImportPublicKey(const LPTTWFSPINEMVIMPORTPUBLICKEY lpEMVImportPublicKey, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_EMV_IMPORT_PUBLIC_KEY, lpEMVImportPublicKey, ReqID, Timeout);
	}
	bool  CTTPIN::AsyncDigest(const LPTTWFSPINDIGEST lpDigest, REQUESTID& ReqID, const DWORD Timeout) noexcept
	{
		return TTAsyncExecute(WFS_CMD_PIN_DIGEST, lpDigest, ReqID, Timeout);
	}
}
