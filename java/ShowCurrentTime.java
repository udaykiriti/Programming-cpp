public class ShowCurrentTime{
    public static void main(String[] args) {
        long total=System.currentTimeMillis();
        long ts=total/1000;
        long currs=ts%60;
        long tm=ts/60;
        long cm=tm%60;
        long th=tm%24;
        long ch=th%24;
        System.out.println("Current time "+ch+ ":"+cm+":"+currs+" GMT");
    }
}