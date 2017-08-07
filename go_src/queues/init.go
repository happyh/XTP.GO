package queues

import (
	"unsafe"
)

type ChanMsg struct {
	SpiPtr uint64
	Type   EventType
	Data   unsafe.Pointer
	Err    unsafe.Pointer
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

func Enqueue(queue *chan ChanMsg, spiPtr uint64, _type EventType, data unsafe.Pointer, err unsafe.Pointer) {
	var msg ChanMsg
	msg.SpiPtr = spiPtr
	msg.Type = _type
	msg.Data = data
	msg.Err = err
	(*queue) <- msg
}