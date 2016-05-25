#if !defined(__GNUC__) && !defined(__i386__) && !defined(__x86_64__)
#error x86 GCC is required to compile this file.
#endif

#include <gcj/cni.h>

class CPUID: public java::lang::Object
{
	private:
		static const jstring vendorID;
		static const jstring brandString;
		static jstring nativeGetVendorID();
		static jstring nativeGetBrandString();
		CPUID();

	public:
		static jstring getBrandString();
		static jstring getVendorID();
};

jstring CPUID::nativeGetVendorID()
{
	char vendor[12];

	asm
	(
		"cpuid\n\t"
		"mov\t%%ebx, (%1)\n\t"
		"mov\t%%edx, 4(%1)\n\t"
		"mov\t%%ecx, 8(%1)"
		:
		: "a"(0), "D"(vendor)
		: "%ecx", "%edx", "%ebx"
	);

	return _Jv_NewStringLatin1(vendor, sizeof(vendor));
}

jstring CPUID::nativeGetBrandString()
{
	char brand[48];

	asm
	(
		"push %1\n"
		"1:\n\t"
		"mov\t%0, %%eax\n\t"
		"cpuid\n\t"
		"mov\t%%eax, (%1)\n\t"
		"mov\t%%ebx, 4(%1)\n\t"
		"mov\t%%ecx, 8(%1)\n\t"
		"mov\t%%edx, 12(%1)\n\t"
		"inc\t%0\n\t"
		"add\t$16, %1\n\t"
		"cmp\t$0x80000004, %0\n\t"
		"jbe\t1b\n\t"
		"pop\t%1"
		:
		: "S"(0x80000002), "D"(brand)
		: "%eax", "%ecx", "%edx", "%ebx"
	);

	return JvNewStringLatin1(brand);
}
