package org.opendedup.buse.sample;


import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.util.logging.ConsoleHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

import org.opendedup.buse.driver.*;

public class FBBlkDev implements BUSE {

	MappedByteBuffer mem = null;
	RandomAccessFile aFile = null;
	private static Logger log = Logger.getLogger(FBBlkDev.class.getName());
	
	static {
		ConsoleHandler handler = new ConsoleHandler();
		handler.setFormatter(new SimpleFormatter());
		log.addHandler(handler);
	}
	
	public FBBlkDev(int sz, String file) throws IOException {
		aFile = new RandomAccessFile
                (file, "rw");
        FileChannel inChannel = aFile.getChannel();
        mem = inChannel.map(FileChannel.MapMode.READ_WRITE, 0, sz);
        mem.load();
	}
	
	@Override
	public int read(ByteBuffer data, int len, long offset) {
		log.fine("read request len=" + len + " offset=" + offset);
		byte [] b = new byte[len];
		mem.get(b, (int)offset, len);
		data.put(b, 0, b.length);
		return 0;
	}

	@Override
	public int write(ByteBuffer buff, int len, long offset) {
		log.fine("write request len=" + len + " offset=" + offset);
		byte [] b = new byte[len];
		buff.get(b, 0, len);
		mem.put(b, (int)offset, len);
		return 0;
	}

	@Override
	public void disconnect() {
		log.fine("disconnect request");
		try {
			//BUSEMkDev.closedev();
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.exit(0);
		
	}

	@Override
	public int flush() {
		log.fine("flush request");
		mem.force();
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int trim(long from, int len) {
		log.fine("trim request from=" + from + " len=" + len);
		byte [] b = new byte[len];
		mem.put(b, (int)from, len);
		return 0;
	}
	
	public static void main(String [] args) throws Exception {
		int sz = 128 * 1024 *1024*10;
		BUSEMkDev.init();
		FBBlkDev loop = new FBBlkDev(sz,"test.bin");
		log.setLevel(Level.FINE);
		BUSEMkDev.startdev("/dev/nbd0", sz,1024, loop, false);
	}

	@Override
	public void close() {
		try {
			aFile.getFD().sync();
			aFile.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

}
