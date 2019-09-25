public class m_sort {


    public static void main(String args[])
    {
        int[] a={2,5,3,6,8,1,7};
        for(int i=0;i<a.length;i++)
        {
            System.out.print(a[i] + " ");
        }

        mergeSort(a,0,a.length-1);
        System.out.println();
        for(int i=0;i<a.length;i++)
        {
            System.out.print(a[i] + " ");
        }
    }

    static void  mergeSort(int[] a,int start,int end) {
        if(start<end)
        {
            int mid=(start+end)/2;
            mergeSort(a,start,mid);
            mergeSort(a,mid+1,end);
            merge(a,start,mid,end);
        }
    }
   static void merge(int []a,int start,int mid,int end)
    {
        int n1=mid-start+1;
        int n2=end-mid;
        int[] l_a=new int[n1];
        int []r_a=new int[n2];
        int k=start;
        for(int f=0;f<n1;f++)
        {
            l_a[f]=a[start+f];
        }

        for(int f=0;f<n2;f++)
        {
            r_a[f]=a[mid+f+1];
        }
        int j=0,i=0;
        while(i<n1&&j<n2) {
            if (l_a[i] < r_a[j]) {
                a[k] = l_a[i];
                i++;
            } else {
                a[k] = r_a[j];
                j++;
            }
            k++;
        }
            while(i<n1)
            {
                a[k] = l_a[i];
                i++;
                k++;
            }
            while (j < n2) {
                a[k]=r_a[j];
                k++;
                j++;
            }

    }
}
