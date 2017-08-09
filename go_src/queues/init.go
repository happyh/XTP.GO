package queues

import (
	"time"
	"unsafe"
)

type ChanMsg struct {
	SpiPtr      uint64
	Type        EventType
	Data        unsafe.Pointer
	Err         unsafe.Pointer
	RequestId   int
	IsLast      bool
	TimeToSleep int
	TinQ        time.Time
	TinQStr     string
}

const (
	ChanSize = 4096
)

var QueryQueue chan ChanMsg

var QuoteQueue chan ChanMsg

var TraderQueue chan ChanMsg

func init() {
	QueryQueue = make(chan ChanMsg, ChanSize)
	QuoteQueue = make(chan ChanMsg, ChanSize)
	TraderQueue = make(chan ChanMsg, ChanSize)
}

func Enqueue(queue *chan ChanMsg, spiPtr uint64, _type EventType, data unsafe.Pointer, err unsafe.Pointer, request_id int, isLast int) {
	var msg ChanMsg
	msg.SpiPtr = spiPtr
	msg.Type = _type
	msg.Data = data
	msg.Err = err
	msg.RequestId = int(request_id)
	if isLast != 0 {
		msg.IsLast = true
	} else {
		msg.IsLast = false
	}
	msg.TinQ = time.Now()
	msg.TinQStr = msg.TinQ.Format("20060102 15:04:05.000000")
	(*queue) <- msg
}
