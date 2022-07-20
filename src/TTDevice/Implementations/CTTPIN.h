#pragma once

#ifndef __H_CTTPIN__
#define __H_CTTPIN__

#include "../Interfaces/ITTPIN.h"

namespace TTDevice
{
	class CTTPIN : public ITTPIN
	{
	private:
	protected:
	public:
		CTTPIN() = default;
		CTTPIN(const CTTPIN&) = delete;
		CTTPIN(CTTPIN&&) = delete;
		CTTPIN& operator = (const CTTPIN) = delete;
		CTTPIN& operator = (CTTPIN&&) = delete;
		virtual ~CTTPIN() = default;

		/* PIN Info Commands */
		bool GetStatus(LPTTWFSPINSTATUS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCapabilities(LPTTWFSPINCAPS, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetKeyDetail(const LPSTR, LPTTWFSPINP2APKEYDETAIL, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetFuncKeyDetail(const LPULONG, LPTTWFSPINFUNCKEYDETAIL, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetHSMTData(LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetKeyDetailEx(const LPSTR, LPTTWFSPINP2APKEYDETAILEX, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncGetStatus(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCapabilities(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetKeyDetail(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetFuncKeyDetail(LPULONG, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetHSMTData(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetKeyDetailEx(const LPSTR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/* PIN Execute Commands */
		/// Normal PIN Commands
		bool Crypt(const LPTTWFSPINCRYPT, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ImportKey(const LPTTWFSPINIMPORT, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool DeriveKey(const LPTTWFSPINDERIVE, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetPin(const LPTTWFSPINGETPIN, LPTTWFSPINENTRY, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool LocalDES(const LPTTWFSPINLOCALDES, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool CreateOffset(const LPTTWFSPINCREATEOFFSET, LPTTWFSPINLPSTR, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool LocalEuroCheque(const LPTTWFSPINLOCALEUROCHEQUE, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool LocalVisa(const LPTTWFSPINLOCALVISA, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool PresentIDC(const LPTTWFSPINPRESENTIDC, LPTTWFSPINPRESENTRESULT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetPinBlock(const LPTTWFSPINBLOCK, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetData(const LPTTWFSPINGETDATA, LPTTWFSPINDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Initialization(const LPTTWFSPININIT, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool LocalBankSYS(const LPTTWFSPINLOCALBANKSYS, LPTTWFSPINBOOL, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool BankSYSIO(const LPTTWFSPINBANKSYSIO, LPTTWFSPINBANKSYSIO, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Reset(const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool HSMSetTData(const LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SecureMSGSend(const LPTTWFSPINSECMSG, LPTTWFSPINSECMSG, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool SecureMSGReceive(const LPTTWFSPINSECMSG, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetJournal(const LPWORD, LPTTWFSXDATA, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ImportKeyEx(const LPTTWFSPINIMPORTKEYEX, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ENCIO(const LPTTWFSPINENCIO, LPTTWFSPINENCIO, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool HSMInit(const LPTTWFSPINHSMINIT, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncCrypt(const LPTTWFSPINCRYPT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncImportKey(const LPTTWFSPINIMPORT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncDeriveKey(const LPTTWFSPINDERIVE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetPin(const LPTTWFSPINGETPIN, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncLocalDES(const LPTTWFSPINLOCALDES, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncCreateOffset(const LPTTWFSPINCREATEOFFSET, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncLocalEuroCheque(const LPTTWFSPINLOCALEUROCHEQUE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncLocalVisa(const LPTTWFSPINLOCALVISA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncPresentIDC(const LPTTWFSPINPRESENTIDC, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetPinBlock(const LPTTWFSPINBLOCK, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetData(const LPTTWFSPINGETDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncInitialization(const LPTTWFSPININIT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncLocalBankSYS(const LPTTWFSPINLOCALBANKSYS, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncBankSYSIO(const LPTTWFSPINBANKSYSIO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReset(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncHSMSetTData(const LPTTWFSXDATA, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSecureMSGSend(const LPTTWFSPINSECMSG, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncSecureMSGReceive(const LPTTWFSPINSECMSG, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetJournal(const LPWORD, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncImportKeyEx(const LPTTWFSPINIMPORTKEYEX, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncENCIO(const LPTTWFSPINENCIO, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncHSMInit(const LPTTWFSPINHSMINIT, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/// Common Commands forRemote Key Loading Schemes
		bool StartKeyExchange(const LPTTWFSPINSTARTKEYEXCHANGE, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncStartKeyExchange(REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/// Remote Key Loading Using Signature
		bool ImportRSAPublicKey(const LPTTWFSPINIMPORTRSAPUBLICKEY, LPTTWFSPINIMPORTRSAPUBLICKEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ExportRSAIssuerSignedItem(const LPTTWFSPINEXPORTRSAISSUERSIGNEDITEM, LPTTWFSPINEXPORTRSAISSUERSIGNEDITEMOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ImportRSASignedDESKey(const LPTTWFSPINIMPORTRSASIGNEDDESKEY, LPTTWFSPINIMPORTRSASIGNEDDESKEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GenerateRSAKeyPair(const LPTTWFSPINGENERATERSAKEYPAIR, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ExportRSAEPPSignedItem(const LPTTWFSPINEXPORTRSAEPPSIGNEDITEM, LPTTWFSPINEXPORTRSAEPPSIGNEDITEMOUTPUT, const DWORD = DEFAULT_TIMEOUT)  noexcept final;

		bool AsyncImportRSAPublicKey(const LPTTWFSPINIMPORTRSAPUBLICKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncExportRSAIssuerSignedItem(const LPTTWFSPINEXPORTRSAISSUERSIGNEDITEM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncImportRSASignedDESKey(const LPTTWFSPINIMPORTRSASIGNEDDESKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGenerateRSAKeyPair(const LPTTWFSPINGENERATERSAKEYPAIR, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncExportRSAEPPSignedItem(const LPTTWFSPINEXPORTRSAEPPSIGNEDITEM, REQUESTID&, const DWORD = DEFAULT_TIMEOUT)  noexcept final;

		/// Remote Key Loading Using CERTIFICATES
		bool LoadCertificate(const LPTTWFSPINLOADCERTIFICATE, LPTTWFSPINLOADCERTIFICATEOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool GetCertificate(const LPTTWFSPINGETCERTIFICATE, LPTTWFSPINGETCERTIFICATEOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ReplaceCertificate(const LPTTWFSPINREPLACECERTIFICATE, LPTTWFSPINREPLACECERTIFICATEOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool ImportRSAEncipheredPKCS7Key(const LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY, LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncLoadCertificate(const LPTTWFSPINLOADCERTIFICATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncGetCertificate(const LPTTWFSPINGETCERTIFICATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncReplaceCertificate(const LPTTWFSPINREPLACECERTIFICATE, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncImportRSAEncipheredPKCS7Key(const LPTTWFSPINIMPORTRSAENCIPHEREDPKCS7KEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		/// EMV
		bool EMVImportPublicKey(const LPTTWFSPINEMVIMPORTPUBLICKEY, LPTTWFSPINEMVIMPORTPUBLICKEYOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool Digest(const LPTTWFSPINDIGEST, LPTTWFSPINDIGESTOUTPUT, const DWORD = DEFAULT_TIMEOUT) noexcept final;

		bool AsyncEMVImportPublicKey(const LPTTWFSPINEMVIMPORTPUBLICKEY, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
		bool AsyncDigest(const LPTTWFSPINDIGEST, REQUESTID&, const DWORD = DEFAULT_TIMEOUT) noexcept final;
	};
}
#endif // !__H_CTTPIN__
