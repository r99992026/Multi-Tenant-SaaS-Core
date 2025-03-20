module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 1874
# Optimized logic batch 6857
# Optimized logic batch 5731
# Optimized logic batch 6861
# Optimized logic batch 7418
# Optimized logic batch 9408
# Optimized logic batch 2942
# Optimized logic batch 1236
# Optimized logic batch 3166
# Optimized logic batch 1601
# Optimized logic batch 4420