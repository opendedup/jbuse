package org.opendedup.buse.sample;

import java.nio.ByteBuffer;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.logging.ConsoleHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

import org.opendedup.buse.driver.*;

public class MemBlkDev implements BUSE {

	ByteBuffer mem = null;
	private static Logger log = Logger.getLogger(MemBlkDev.class.getName());
	ReentrantReadWriteLock lock = new ReentrantReadWriteLock();

	static {
		ConsoleHandler handler = new ConsoleHandler();
		handler.setFormatter(new SimpleFormatter());
		log.addHandler(handler);
		log.setLevel(Level.FINEST);
	}

	public MemBlkDev(int sz) {
		mem = ByteBuffer.allocateDirect(sz);
	}

	
	@Override
	public int read(ByteBuffer data, int len, long offset) {
		log.fine("read request len=" + len + " offset="
				+ (int) offset + " databuflen=" + data.capacity()
				+ " databufpos=" + data.position() + " membufsz="
				+ mem.capacity());
		byte[] b = new byte[len];
		Lock l = lock.writeLock();
		l.lock();
		try {
			mem.position((int) offset);
			mem.get(b);
		} finally {
			l.unlock();
		}
		data.put(b);
		return 0;
	}

	@Override
	public int write(ByteBuffer buff, int len, long offset) {
		log.fine("write request len=" + len + " offset="
				+ (int) offset + " databuflen=" + buff.capacity()
				+ " databufpos=" + buff.position() + " membufsz="
				+ mem.capacity());
		byte[] b = new byte[len];
		buff.get(b, 0, len);
		Lock l = lock.writeLock();
		l.lock();
		try {
			mem.position((int) offset);
			mem.put(b);
		} finally {
			l.unlock();
		}
		return 0;
	}

	@Override
	public void disconnect() {
		log.fine("disconnect request");
		try {
			// BUSEMkDev.closedev();
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.exit(0);

	}

	@Override
	public int flush() {
		log.fine("flush request");
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int trim(long from, int len) {
		log.fine("trim request from=" + from + " len=" + len);
		Lock l = lock.writeLock();
		l.lock();
		try {
			byte[] b = new byte[len];
			mem.position((int) from);
			mem.put(b, 0, len);
		} finally {
			l.unlock();
		}
		return 0;
	}

	public static void main(String[] args) throws Exception {
		int sz = 128 * 1024 * 1024;
		BUSEMkDev.init();
		MemBlkDev loop = new MemBlkDev(sz);
		log.setLevel(Level.FINE);
		BUSEMkDev.startdev("/dev/nbd0", sz,1024, loop, false);
	}

	@Override
	public void close() {
		// TODO Auto-generated method stub

	}

}
