public class Test
{
	public static void main(String[] args) throws Exception
	{
		System.out.println("CPUID-GCJ test");
		System.out.println("CPU vendor ID:\t" + CPUID.getVendorID());
		System.out.println("CPU brand string:\t" + CPUID.getBrandString());
	}
}
