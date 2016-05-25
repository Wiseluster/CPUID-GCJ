public final class CPUID
{
	private static final String vendorID = nativeGetVendorID();
	private static final String brandString = nativeGetBrandString();
	private native static String nativeGetVendorID();
	private native static String nativeGetBrandString();

	private CPUID()
	{
	}

	public static String getVendorID()
	{
		return vendorID;
	}

	public static String getBrandString()
	{
		return brandString;
	}
}
